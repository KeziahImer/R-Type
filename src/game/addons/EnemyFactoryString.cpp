#include "Rtype/addons/EnemyFactory.hpp"
#include "Rtype/addons/PatternMovement.hpp"
#include <iostream>
#include <string>

std::string Rtype::Addons::getEntityTypeString(
    std::pair<std::map<std::string, ValueFirstMap>,
              std::map<std::string, Value>>
        enemy) {
  if (enemy == ENEMY_TYPE_1)
    return "enemy_type_1";
  if (enemy == ENEMY_TYPE_2)
    return "enemy_type_2";
  if (enemy == ENEMY_TYPE_3)
    return "enemy_type_3";
  if (enemy == ENEMY_TYPE_4)
    return "enemy_type_4";
  if (enemy == BOSS_TYPE_1)
    return "boss_1";
  if (enemy == BOSS_TYPE_2_BODY)
    return "boss_2_body";
  if (enemy == BOSS_TYPE_2_HEAD)
    return "boss_2_head";
  if (enemy == BOSS_TYPE_3_1)
    return "boss_3_1";
  if (enemy == BOSS_TYPE_3_2)
    return "boss_3_2";
  if (enemy == BOSS_TYPE_3_3)
    return "boss_3_3";
  if (enemy == BOSS_TYPE_3_BODY)
    return "boss_3_body";
  return "enemy_type_1";
}

std::pair<std::map<std::string, ValueFirstMap>, std::map<std::string, Value>>
Rtype::Addons::getEntityTypeByString(std::string enemy) {
  if (enemy == "enemy_type_1")
    return ENEMY_TYPE_1;
  if (enemy == "enemy_type_2")
    return ENEMY_TYPE_2;
  if (enemy == "enemy_type_3")
    return ENEMY_TYPE_3;
  if (enemy == "enemy_type_4")
    return ENEMY_TYPE_4;
  if (enemy == "boss_1")
    return BOSS_TYPE_1;
  if (enemy == "boss_2_body")
    return BOSS_TYPE_2_BODY;
  if (enemy == "boss_2_head")
    return BOSS_TYPE_2_HEAD;
  if (enemy == "boss_3_1")
    return BOSS_TYPE_3_1;
  if (enemy == "boss_3_2")
    return BOSS_TYPE_3_2;
  if (enemy == "boss_3_3")
    return BOSS_TYPE_3_3;
  if (enemy == "boss_3_body")
    return BOSS_TYPE_3_BODY;
  return ENEMY_TYPE_1;
}