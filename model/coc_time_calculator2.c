#include <stdio.h>
#include <time.h>
#include <string.h>

#define MAX_ENTRIES 100
#define BOOST_DURATION 22    // 22 minutes of boost at level 5
#define BOOST_MULTIPLIER 10  // 10x speed during boost
#define BOOST_COOLDOWN 1320  // 22 hours cooldown in minutes

typedef struct {
    char name[50];
    time_t completion_time;
    int is_clock_tower;
} Upgrade;

time_t calculate_builder_completion(int days, int hours, int minutes, time_t *next_boost_time) {
    int total_minutes = days * 24 * 60 + hours * 60 + minutes;
    time_t current_time = time(NULL);

    if (*next_boost_time <= current_time) {
        // Boost is available immediately

        if (total_minutes <= BOOST_DURATION) {
            // Entire upgrade done during boost period (10x speed)
            int real_seconds = (total_minutes * 60) / BOOST_MULTIPLIER;
            *next_boost_time = current_time + BOOST_COOLDOWN * 60; // reset cooldown
            return current_time + real_seconds;
        } else {
            // Part of upgrade is boosted, part at normal speed
            int boosted_part = BOOST_DURATION;
            int normal_part = total_minutes - BOOST_DURATION;

            int boosted_seconds = (boosted_part * 60) / BOOST_MULTIPLIER; // boosted real time
            int normal_seconds = normal_part * 60;

            *next_boost_time = current_time + BOOST_COOLDOWN * 60; // reset cooldown
            return current_time + boosted_seconds + normal_seconds;
        }
    } else {
        // Boost not ready yet

        int minutes_until_boost = (*next_boost_time - current_time) / 60;

        if (total_minutes <= minutes_until_boost) {
            // Finishes before boost starts, no boost applied
            return current_time + total_minutes * 60;
        } else {
            // Overlaps with boost start

            int normal_before_boost = minutes_until_boost;
            int remaining_minutes = total_minutes - normal_before_boost;

            if (remaining_minutes <= BOOST_DURATION) {
                // Partial boost for remaining time
                int boosted_seconds = (remaining_minutes * 60) / BOOST_MULTIPLIER;
                *next_boost_time += BOOST_COOLDOWN * 60;
                return current_time + normal_before_boost * 60 + boosted_seconds;
            } else {
                // Full boost duration then normal speed for rest
                int boosted_seconds = (BOOST_DURATION * 60) / BOOST_MULTIPLIER;
                int normal_after_boost = remaining_minutes - BOOST_DURATION;
                *next_boost_time += BOOST_COOLDOWN * 60;
                return current_time + normal_before_boost * 60 + boosted_seconds + normal_after_boost * 60;
            }
        }
    }
}

int main() {
    Upgrade upgrades[MAX_ENTRIES];
    int main_count, builder_count, total = 0;
    int ct_hr = 0, ct_min = 0;

    printf("Enter number of Main Base upgrades: ");
    scanf("%d", &main_count);
    getchar();

    printf("Enter number of Builder Base upgrades: ");
    scanf("%d", &builder_count);
    getchar();

    if (main_count + builder_count > MAX_ENTRIES) {
        printf("Error: Maximum entries exceeded (%d)\n", MAX_ENTRIES);
        return 1;
    }

    printf("\n---- Main Base ----\n");
    for (int i = 0; i < main_count; i++) {
        char name[50];
        int d, h, m;

        printf("Upgrade %d:\nName: ", i + 1);
        fgets(name, sizeof(name), stdin);
        name[strcspn(name, "\n")] = 0;

        printf("Time (days hours minutes): ");
        scanf("%d %d %d", &d, &h, &m);
        getchar();

        time_t finish = time(NULL) + d * 86400 + h * 3600 + m * 60;
        strcpy(upgrades[total].name, name);
        upgrades[total].completion_time = finish;
        upgrades[total].is_clock_tower = 0;
        total++;
    }

    time_t next_boost_time = 0;

    if (builder_count > 0) {
        printf("\n---- Builder Base ----\n");
        printf("Enter time until next Clock Tower boost (hours minutes): ");
        scanf("%d %d", &ct_hr, &ct_min);
        getchar();

        next_boost_time = time(NULL) + (ct_hr * 60 + ct_min) * 60;

        for (int i = 0; i < builder_count; i++) {
            char name[50];
            int d, h, m;

            printf("Entry %d:\nName: ", i + 1);
            fgets(name, sizeof(name), stdin);
            name[strcspn(name, "\n")] = 0;

            printf("Time (days hours minutes): ");
            scanf("%d %d %d", &d, &h, &m);
            getchar();

            time_t finish = calculate_builder_completion(d, h, m, &next_boost_time);
            strcpy(upgrades[total].name, name);
            upgrades[total].completion_time = finish;
            upgrades[total].is_clock_tower = 0;
            total++;
        }

        // Add Clock Tower entry
        strcpy(upgrades[total].name, "Clock Tower Boost Ready");
        upgrades[total].completion_time = next_boost_time;
        upgrades[total].is_clock_tower = 1;
        total++;
    }

    // Sort by completion time
    for (int i = 0; i < total - 1; i++) {
        for (int j = i + 1; j < total; j++) {
            if (upgrades[i].completion_time > upgrades[j].completion_time) {
                Upgrade temp = upgrades[i];
                upgrades[i] = upgrades[j];
                upgrades[j] = temp;
            }
        }
    }

    printf("\n=== Upgrade Schedule ===\n");
    for (int i = 0; i < total; i++) {
        struct tm *lt = localtime(&upgrades[i].completion_time);
        char buffer[100];
        strftime(buffer, sizeof(buffer), "(%b %d) %I:%M %p", lt);

        if (upgrades[i].is_clock_tower) {
            printf("[CLOCK TOWER]%17s\n", buffer);
        } else {
            printf("%-20s %s\n", upgrades[i].name, buffer);
        }
    }

    return 0;
}
