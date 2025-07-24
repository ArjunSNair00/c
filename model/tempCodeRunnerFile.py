from datetime import datetime, timedelta

def parse_time_input(time_str):
    parts = time_str.strip().split()
    if len(parts) != 3:
        raise ValueError("Enter time as: days hours minutes (e.g. '0 1 0')")
    days, hours, minutes = map(int, parts)
    return timedelta(days=days, hours=hours, minutes=minutes)

def simulate_upgrade_finish(upgrade_time, boost_times):
    BOOST_DURATION_REAL = timedelta(minutes=22)
    BOOST_MULTIPLIER = 9
    COOLDOWN_DURATION_REAL = timedelta(hours=22)

    now = datetime.now()
    current_time = now
    remaining_upgrade_time = upgrade_time
    boost_index = 0

    while remaining_upgrade_time > timedelta(0):
        if boost_index < len(boost_times) and current_time >= boost_times[boost_index]:
            # Apply boost
            max_reduction = BOOST_DURATION_REAL * BOOST_MULTIPLIER
            if remaining_upgrade_time <= max_reduction:
                real_time = remaining_upgrade_time / BOOST_MULTIPLIER
                current_time += real_time
                remaining_upgrade_time = timedelta(0)
            else:
                current_time += BOOST_DURATION_REAL
                remaining_upgrade_time -= max_reduction
            boost_index += 1
        else:
            # Wait for next boost or finish normally
            if boost_index < len(boost_times):
                wait_time = boost_times[boost_index] - current_time
                if remaining_upgrade_time <= wait_time:
                    current_time += remaining_upgrade_time
                    remaining_upgrade_time = timedelta(0)
                else:
                    current_time = boost_times[boost_index]
            else:
                current_time += remaining_upgrade_time
                remaining_upgrade_time = timedelta(0)

    return current_time

def get_upgrades(num_upgrades, use_boosts=False, boost_start_time=None):
    upgrades = []
    boost_times = []

    if use_boosts and boost_start_time:
        # Generate boost windows every 22h after the first one
        BOOST_DURATION = timedelta(minutes=22)
        BOOST_COOLDOWN = timedelta(hours=22)
        next_boost = boost_start_time
        while len(boost_times) < 100:
            boost_times.append(next_boost)
            next_boost += BOOST_DURATION + BOOST_COOLDOWN

    for i in range(num_upgrades):
        print(f"\nEntry {i+1}:")
        name = input("Upgrade name: ")
        time_left_str = input("Time left (days hours minutes): ")
        upgrade_time = parse_time_input(time_left_str)

        if use_boosts and boost_start_time:
            finish_time = simulate_upgrade_finish(upgrade_time, boost_times)
        else:
            finish_time = datetime.now() + upgrade_time

        upgrades.append((name, finish_time))

    return upgrades, boost_times[0] if boost_times else None

def format_upgrade(name, dt):
    return f"{name:<22} ({dt.strftime('%b %d')}) {dt.strftime('%I:%M %p')}"

def main():
    print("Clash of Clans Upgrade Finish Time Calculator with Clock Tower Boost\n")

    main_count = int(input("Number of main base upgrades: "))
    builder_count = int(input("Number of builder base upgrades: "))

    print("\n--- Main Base Upgrades ---")
    main_upgrades, _ = get_upgrades(main_count)

    print("\n--- Builder Base Upgrades ---")
    cooldown_input = input("Enter Clock Tower cooldown left (hours minutes, e.g. '0 0' if ready): ")
    cooldown_parts = cooldown_input.strip().split()
    if len(cooldown_parts) != 2:
        print("Invalid cooldown input.")
        return
    cooldown_left = timedelta(hours=int(cooldown_parts[0]), minutes=int(cooldown_parts[1]))

    use_boost = False
    boost_start_time = None

    if cooldown_left == timedelta(0):
        confirm = input("Do you want to simulate using the Clock Tower boost now? (y/n): ").strip().lower()
        if confirm == 'y':
            use_boost = True
            boost_start_time = datetime.now()

    builder_upgrades, first_boost_time = get_upgrades(builder_count, use_boost, boost_start_time)

    all_upgrades = main_upgrades + builder_upgrades

    # Always calculate next [CLOCK TOWER] availability
    if use_boost and first_boost_time:
        # Used now: available after 22 min + 22 h
        clock_tower_available = first_boost_time + timedelta(minutes=22) + timedelta(hours=22)
    else:
        # Not used yet: available in current cooldown
        clock_tower_available = datetime.now() + cooldown_left

    all_upgrades.append(("[CLOCK TOWER]", clock_tower_available))

    all_upgrades.sort(key=lambda x: x[1])

    print("\n=== Upgrade Schedule ===")
    for name, dt in all_upgrades:
        print(format_upgrade(name, dt))

if __name__ == "__main__":
    main()
