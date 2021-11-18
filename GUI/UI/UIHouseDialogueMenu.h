#pragma once

#include <cstdint>


enum HOUSE_DIALOGUE_MENU : int32_t {
    HOUSE_DIALOGUE_NULL = 0,
    HOUSE_DIALOGUE_MAIN = 1,
    HOUSE_DIALOGUE_SHOP_BUY_STANDARD = 2,
    HOUSE_DIALOGUE_SHOP_SELL = 3,
    HOUSE_DIALOGUE_SHOP_IDENTIFY = 4,
    HOUSE_DIALOGUE_SHOP_REPAIR = 5,
    HOUSE_DIALOGUE_SHOP_6 = 6,
    HOUSE_DIALOGUE_BANK_PUT_GOLD = 7,
    HOUSE_DIALOGUE_BANK_GET_GOLD = 8,
    HOUSE_DIALOGUE_9 = 9,
    HOUSE_DIALOGUE_TEMPLE_HEAL = 10,
    HOUSE_DIALOGUE_TEMPLE_DONATE = 11,
    HOUSE_DIALOGUE_12 = 12,
    HOUSE_DIALOGUE_13 = 13,
    HOUSE_DIALOGUE_14 = 14,
    HOUSE_DIALOGUE_TAVERN_REST = 15,
    HOUSE_DIALOGUE_TAVERN_BUY_FOOD = 16,
    HOUSE_DIALOGUE_TRAININGHALL_TRAIN = 17,
    HOUSE_DIALOGUE_GUILD_BUY_BOOKS = 18,
    //...
    HOUSE_DIALOGUE_36 = 36,
    //..
    HOUSE_DIALOGUE_GUILD_LEARN_SKILL = 72,
    //...
    HOUSE_DIALOGUE_SHOP_DISPLAY_EQUIPMENT = 94,
    HOUSE_DIALOGUE_SHOP_BUY_SPECIAL = 95,
    HOUSE_DIALOGUE_LEARN_SKILLS = 96,
    HOUSE_DIALOGUE_97 = 97,
    HOUSE_DIALOGUE_98 = 98,
    HOUSE_DIALOGUE_TOWNHALL_MESSAGE = 99,
    HOUSE_DIALOGUE_TOWNHALL_PAY_FINE = 100,
    HOUSE_DIALOGUE_TAVERN_ARCOMAGE_MAIN = 101,
    HOUSE_DIALOGUE_TAVERN_ARCOMAGE_RULES = 102,
    HOUSE_DIALOGUE_TAVERN_ARCOMAGE_VICTORY_CONDITIONS = 103,
    HOUSE_DIALOGUE_TAVERN_ARCOMAGE_RESULT = 104,
    HOUSE_DIALOGUE_TRANSPORT_SCHEDULE_1 = 105,
    HOUSE_DIALOGUE_TRANSPORT_SCHEDULE_2 = 106,
    HOUSE_DIALOGUE_TRANSPORT_SCHEDULE_3 = 107,
    HOUSE_DIALOGUE_TRANSPORT_SCHEDULE_4 = 108,
    HOUSE_DIALOGUE_OTHER = -1
};