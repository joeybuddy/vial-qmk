/* Copyright 2023 @ Keychron (https://www.keychron.com)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "quantum.h"
#include "ckled2001_compat.h"

// clang-format off
#ifdef RGB_MATRIX_ENABLE
const snled27351_led_t PROGMEM g_snled27351_leds[RGB_MATRIX_LED_COUNT] = {
/* Refer to SNLED27351 manual for these locations
 *   driver
 *   |  R location
 *   |  |       G location
 *   |  |       |       B location
 *   |  |       |       | */
    {0, SW1_CS1,   SW1_CS2,    SW1_CS3},
    {0, SW2_CS1,   SW2_CS2,    SW2_CS3},
    {0, SW3_CS1,   SW3_CS2,    SW3_CS3},
    {0, SW4_CS1,   SW4_CS2,    SW4_CS3},
    {0, SW5_CS1,   SW5_CS2,    SW5_CS3},
    {0, SW6_CS1,   SW6_CS2,    SW6_CS3},
    {0, SW7_CS1,   SW7_CS2,    SW7_CS3},
    {0, SW8_CS1,   SW8_CS2,    SW8_CS3},
    {0, SW9_CS1,   SW9_CS2,    SW9_CS3},
    {0, SW10_CS1,  SW10_CS2,   SW10_CS3},
    {0, SW11_CS1,  SW11_CS2,   SW11_CS3},
    {0, SW12_CS1,  SW12_CS2,   SW12_CS3},
    {0, SW1_CS4,   SW1_CS5,    SW1_CS6},
    {0, SW2_CS4,   SW2_CS5,    SW2_CS6},
    {0, SW3_CS4,   SW3_CS5,    SW3_CS6},
    {0, SW4_CS4,   SW4_CS5,    SW4_CS6},

    {0, SW9_CS10,  SW9_CS11,   SW9_CS12},
    {0, SW10_CS10, SW10_CS11,  SW10_CS12},
    {0, SW11_CS10, SW11_CS11,  SW11_CS12},
    {0, SW12_CS10, SW12_CS11,  SW12_CS12},
    {0, SW1_CS10,  SW1_CS11,   SW1_CS12},
    {0, SW2_CS10,  SW2_CS11,   SW2_CS12},
    {0, SW3_CS10,  SW3_CS11,   SW3_CS12},
    {0, SW4_CS10,  SW4_CS11,   SW4_CS12},
    {0, SW5_CS10,  SW5_CS11,   SW5_CS12},
    {0, SW6_CS10,  SW6_CS11,   SW6_CS12},
    {0, SW7_CS10,  SW7_CS11,   SW7_CS12},
    {0, SW8_CS10,  SW8_CS11,   SW8_CS12},
    {0, SW9_CS7,   SW9_CS8,    SW9_CS9},
    {0, SW10_CS7,  SW10_CS8,   SW10_CS9},
    {0, SW12_CS10, SW12_CS11,  SW12_CS12},

    {0, SW5_CS4,   SW5_CS5,    SW5_CS6},
    {0, SW6_CS4,   SW6_CS5,    SW6_CS6},
    {0, SW7_CS4,   SW7_CS5,    SW7_CS6},
    {0, SW8_CS4,   SW8_CS5,    SW8_CS6},
    {0, SW9_CS4,   SW9_CS5,    SW9_CS6},
    {0, SW10_CS4,  SW10_CS5,   SW10_CS6},
    {0, SW11_CS4,  SW11_CS5,   SW11_CS6},
    {0, SW12_CS4,  SW12_CS5,   SW12_CS6},
    {0, SW1_CS7,   SW1_CS8,    SW1_CS9},
    {0, SW2_CS7,   SW2_CS8,    SW2_CS9},
    {0, SW3_CS7,   SW3_CS8,    SW3_CS9},
    {0, SW4_CS7,   SW4_CS8,    SW4_CS9},
    {0, SW5_CS7,   SW5_CS8,    SW5_CS9},
    {0, SW6_CS7,   SW6_CS8,    SW6_CS9},
    {0, SW8_CS7,   SW8_CS8,    SW8_CS9},

    {1, SW1_CS1,   SW1_CS2,    SW1_CS3},
    {1, SW2_CS1,   SW2_CS2,    SW2_CS3},
    {1, SW3_CS1,   SW3_CS2,    SW3_CS3},
    {1, SW4_CS1,   SW4_CS2,    SW4_CS3},
    {1, SW5_CS1,   SW5_CS2,    SW5_CS3},
    {1, SW6_CS1,   SW6_CS2,    SW6_CS3},
    {1, SW7_CS1,   SW7_CS2,    SW7_CS3},
    {1, SW8_CS1,   SW8_CS2,    SW8_CS3},
    {1, SW9_CS1,   SW9_CS2,    SW9_CS3},
    {1, SW10_CS1,  SW10_CS2,   SW10_CS3},
    {1, SW11_CS1,  SW11_CS2,   SW11_CS3},
    {1, SW12_CS1,  SW12_CS2,   SW12_CS3},
    {1, SW2_CS4,   SW2_CS5,    SW2_CS6},
    {1, SW4_CS4,   SW4_CS5,    SW4_CS6},

    {1, SW5_CS4,   SW5_CS5,    SW5_CS6},
    {1, SW7_CS4,   SW7_CS5,    SW7_CS6},
    {1, SW8_CS4,   SW8_CS5,    SW8_CS6},
    {1, SW9_CS4,   SW9_CS5,    SW9_CS6},
    {1, SW10_CS4,  SW10_CS5,   SW10_CS6},
    {1, SW11_CS4,  SW11_CS5,   SW11_CS6},
    {1, SW12_CS4,  SW12_CS5,   SW12_CS6},
    {1, SW1_CS7,   SW1_CS8,    SW1_CS9},
    {1, SW2_CS7,   SW2_CS8,    SW2_CS9},
    {1, SW3_CS7,   SW3_CS8,    SW3_CS9},
    {1, SW4_CS7,   SW4_CS8,    SW4_CS9},
    {1, SW6_CS7,   SW6_CS8,    SW6_CS9},
    {1, SW7_CS7,   SW7_CS8,    SW7_CS9},
    {1, SW8_CS7,   SW8_CS8,    SW8_CS9},

    {1, SW9_CS10,  SW9_CS11,   SW9_CS12},
    {1, SW10_CS10, SW10_CS11,  SW10_CS12},
    {1, SW11_CS10, SW11_CS11,  SW11_CS12},
    {1, SW3_CS10,  SW3_CS11,   SW3_CS12},
    {1, SW7_CS10,  SW7_CS11,   SW7_CS12},
    {1, SW8_CS10,  SW8_CS11,   SW8_CS12},
    {1, SW9_CS7,   SW9_CS8,    SW9_CS9},
    {1, SW10_CS7,  SW10_CS8,   SW10_CS9},
    {1, SW11_CS7,  SW11_CS8,   SW11_CS9},
    {1, SW12_CS10, SW12_CS11,  SW12_CS12},

};

led_config_t g_led_config = {
    {
        { 0,      1,      2,      3,      4,      5,      6,      7,      8,      9,      10,     11,     12,     13,     14,     15 },
        { 16,     17,     18,     19,     20,     21,     22,     23,     24,     25,     26,     27,     28,     29,     NO_LED, 30 },
        { 31,     32,     33,     34,     35,     36,     37,     38,     39,     40,     41,     42,     43,     44,     NO_LED, 45 },
        { 46,     47,     48,     49,     50,     51,     52,     53,     54,     55,     56,     57,     NO_LED, 58,     NO_LED, 59 },
        { 60,     NO_LED, 61,     62,     63,     64,     65,     66,     67,     68,     69,     70,     NO_LED, 71,     72,     73 },
        { 74,     75,     76,     NO_LED, NO_LED, NO_LED, 77,     NO_LED, NO_LED, NO_LED, 78,     79,     80,     81,     82,     83 }
    },
    {
        {0, 0}, {14, 0}, {29, 0}, {44, 0}, {59, 0}, {74, 0}, { 89,  0}, {104,  0}, {119,  0}, {134,  0}, {149,  0}, {164,  0}, {179,  0}, {194,  0}, {209,  0}, {223,  0},
        {0,12}, {14,12}, {29,12}, {44,12}, {59,12}, {74,12}, { 89, 12}, {104, 12}, {119, 12}, {134, 12}, {149, 12}, {164, 12}, {179, 12}, {201, 12},            {223, 12},
        {3,25}, {22,25}, {37,25}, {52,25}, {67,25}, {82,25}, { 97, 25}, {112, 25}, {126, 25}, {141, 25}, {156, 25}, {171, 25}, {186, 25}, {205, 25},            {223, 25},
        {5,38}, {26,38}, {41,38}, {55,38}, {70,38}, {85,38}, {100, 38}, {115, 38}, {130, 38}, {145, 38}, {160, 38}, {175, 38},            {199, 38},            {223, 38},
        {9,51},          {33,51}, {48,51}, {63,51}, {78,51}, { 93, 51}, {108, 51}, {123, 51}, {138, 51}, {153, 51}, {168, 51},            {188, 51}, {209, 51}, {223, 51},
        {1,64}, {20,64}, {39,64},                            { 95, 64},                                  {149, 64}, {164, 64}, {179, 64}, {194, 64}, {209, 64}, {223, 64}
    },
    {
        4,   4,   4,   4,   4,   4,   4,   4,   4,   4,   4,   4,   4,   4,   4,   4,
        4,   4,   4,   4,   4,   4,   4,   4,   4,   4,   4,   4,   4,   4,        4,
        4,   4,   4,   4,   4,   4,   4,   4,   4,   4,   4,   4,   4,   4,        4,
        4,   4,   4,   4,   4,   4,   4,   4,   4,   4,   4,   4,        4,        4,
        4,        4,   4,   4,   4,   4,   4,   4,   4,   4,   4,        4,   4,   4,
        4,   4,   4,                  4,                  4,   4,   4,   4,   4,   4

    }
};
#endif
