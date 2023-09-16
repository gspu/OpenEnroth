#include "CodeGenEnums.h"

#include "Library/Serialization/EnumSerialization.h"

MM_DEFINE_ENUM_SERIALIZATION_FUNCTIONS(BuildingType, CASE_INSENSITIVE, {
    {BUILDING_WEAPON_SHOP,          "WEAPON_SHOP"},
    {BUILDING_ARMOR_SHOP,           "ARMOR_SHOP"},
    {BUILDING_MAGIC_SHOP,           "MAGIC_SHOP"},
    {BUILDING_ALCHEMY_SHOP,         "ALCHEMY_SHOP"},
    {BUILDING_FIRE_GUILD,           "FIRE_GUILD"},
    {BUILDING_AIR_GUILD,            "AIR_GUILD"},
    {BUILDING_WATER_GUILD,          "WATER_GUILD"},
    {BUILDING_EARTH_GUILD,          "EARTH_GUILD"},
    {BUILDING_SPIRIT_GUILD,         "SPIRIT_GUILD"},
    {BUILDING_MIND_GUILD,           "MIND_GUILD"},
    {BUILDING_BODY_GUILD,           "BODY_GUILD"},
    {BUILDING_LIGHT_GUILD,          "LIGHT_GUILD"},
    {BUILDING_DARK_GUILD,           "DARK_GUILD"},
    {BUILDING_ELEMENTAL_GUILD,      "ELEMENTAL_GUILD"},
    {BUILDING_SELF_GUILD,           "SELF_GUILD"},
    {BUILDING_MIRRORED_PATH_GUILD,  "MIRRORED_PATH_GUILD"},
    {BUILDING_TOWN_HALL,            "TOWN_HALL"},
    {BUILDING_MERCENARY_GUILD,      "MERCENARY_GUILD"},
    {BUILDING_THRONE_ROOM,          "THRONE_ROOM"},
    {BUILDING_TAVERN,               "TAVERN"},
    {BUILDING_BANK,                 "BANK"},
    {BUILDING_TEMPLE,               "TEMPLE"},
    {BUILDING_CASTLE,               "CASTLE"},
    {BUILDING_DUNGEON,              "DUNGEON"},
    {BUILDING_SEER,                 "SEER"},
    {BUILDING_STABLE,               "STABLE"},
    {BUILDING_BOAT,                 "BOAT"},
    {BUILDING_TRAINING_GROUND,      "TRAINING_HALL"},
    {BUILDING_JAIL,                 "JAIL"},
    {BUILDING_CIRCUS,               "CIRCUS"},
    {BUILDING_GENERAL_STORE,        "GENERAL_STORE"},
    {BUILDING_SHADOW_GUILD,         "SHADOW_GUILD"},
    {BUILDING_ADVENTURERS_INN,      "ADVENTURERS_INN"},
})
