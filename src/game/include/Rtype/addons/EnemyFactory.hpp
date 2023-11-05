/*
** EPITECH PROJECT, 2023
** R-type
** File description:
** Rtype engine
*/

#ifndef _RTYPE_GAME_COMPONENTS_ENEMYFACTORY_HPP_
#define _RTYPE_GAME_COMPONENTS_ENEMYFACTORY_HPP_

#include "RNGine/Core.hpp"
#include "RNGine/RNGine.hpp"
#include "RNGine/Scene.hpp"
#include <variant>
#include <vector>

using ValueFirstMap = std::variant<
    float, std::pair<bool, RNGine::Addons::CollisionAction>,
    std::pair<float, float>,
    std::pair<int,
              std::pair<bool, std::vector<std::pair<RNGine::Core::Time,
                                                    std::pair<float, float>>>>>,
    std::pair<bool,
              std::vector<std::pair<
                  RNGine::Core::Time,
                  std::pair<RNGine::Core::Time, std::pair<float, float>>>>>>;

using shootAnimationValue =
    std::variant<bool, std::pair<int, int>, RNGine::Core::Time>;

using spriteAnimationValue = std::variant<bool, int>;

using Value =
    std::variant<std::string, int, float, std::map<std::string, float>,
                 std::map<std::string, spriteAnimationValue>,
                 std::map<std::string, shootAnimationValue>>;

const std::pair<std::map<std::string, ValueFirstMap>,
                std::map<std::string, Value>>
    ENEMY_TYPE_1 = {
        {{"width", 2.5f},
         {"height", 2.5f},
         {"velocityX", -400.0f},
         {"velocityY", 0.0f},
         {"positionMob", -1.0f},
         {"winCondition", 0.0f},
         {"makeDamages", 0.0f},
         {"movementPattern",
          std::pair<
              int,
              std::pair<bool, std::vector<std::pair<RNGine::Core::Time,
                                                    std::pair<float, float>>>>>(
              {0,
               {
                   false,
                   {{0, std::make_pair(0.0f, 0.0f)}},
               }})},
         {"shootPattern",
          std::pair<
              bool,
              std::vector<std::pair<
                  RNGine::Core::Time,
                  std::pair<RNGine::Core::Time, std::pair<float, float>>>>>({
              false,
              {{1, std::make_pair(1000.0f, std::make_pair(-1500.0f, 0.0f))}},
          })},
         {"hitboxWidth", 33 * 2.5f},
         {"hitboxHeight", 36 * 2.5f},
         {"originX", 0.0f},
         {"originY", 0.0f},
         {"attackableHealth", 75.0f},
         {"attackableScore", 25.0f},
         {"enemyShootRate", 1000.0f},
         {"velocityShoot", std::pair<float, float>(-1500.0f, 0.0f)},
         {"destroyPositionShoot", std::pair<float, float>(-100.0f, 2020.0f)},
         {"offsetPositionShoot", std::pair<float, float>(-32 * 2.0f, 0.0f)},
         {"scaleShoot", std::pair<float, float>(2.0f, 2.0f)},
         {"hitboxFirst", std::pair<float, float>(32 * 2.0f, 10 * 2.0f)},
         {"hitboxSecond", std::pair<float, float>(0.0f, 0.0f)},
         {"damages", 25.0f},
         {"collider", std::pair<bool, RNGine::Addons::CollisionAction>(
                          false, RNGine::Addons::CollisionAction::None)},
         {"colliderShoot",
          std::pair<bool, RNGine::Addons::CollisionAction>(
              false, RNGine::Addons::CollisionAction::Explosion)}}, // DESIGN
        {{"enemySpritePath", "./assets/enemies.gif"},
         {"bulletSpritePath", "./assets/bullets.gif"},
         {"bulletShootSound", "./assets/sounds/bullet.wav"},
         {"bulletShootSoundVolume", 50.0f},
         {"spriteBulletRect", std::map<std::string, float>{{"x", 33 * 4.0f},
                                                           {"y", 17.0f},
                                                           {"width", 33.0f},
                                                           {"height", 33.0f}}},
         {"bulletAnimation",
          std::map<std::string, shootAnimationValue>{
              {"reverse", false},
              {"loop", false},
              {"multiple", true},
              {"finish", false},
              {"start", std::pair<int, int>(4, 0)},
              {"end", std::pair<int, int>(7, 0)},
              {"lastFrame", std::pair<int, int>(7, 0)},
              {"frequence", (RNGine::Core::Time)150}}},
         {"zIndex", 10},
         {"spriteRect", std::map<std::string, float>{{"x", 8.0f * 33.0f},
                                                     {"y", 0.0f},
                                                     {"width", 33.0f},
                                                     {"height", 36.0f}}},
         {"spriteAnimation", std::map<std::string, spriteAnimationValue>{
                                 {"reverse", false},
                                 {"looping", false},
                                 {"multiple", true},
                                 {"startFrame", 0},
                                 {"endFrame", 3},
                                 {"stopFrame", 0},
                                 {"frequence", 150},
                                 {"lastUpdate", 0}}}}};

const std::pair<std::map<std::string, ValueFirstMap>,
                std::map<std::string, Value>>
    ENEMY_TYPE_2 = {
        {{"width", 1.8f},
         {"height", 1.8f},
         {"velocityX", -200.0f},
         {"velocityY", 0.0f},
         {"positionMob", -1.0f},
         {"winCondition", 0.0f},
         {"makeDamages", 0.0f},
         {"movementPattern",
          std::pair<
              int,
              std::pair<bool, std::vector<std::pair<RNGine::Core::Time,
                                                    std::pair<float, float>>>>>(
              {0,
               {
                   false,
                   {{0, std::make_pair(0.0f, 0.0f)}},
               }})},
         {"shootPattern",
          std::pair<bool,
                    std::vector<std::pair<RNGine::Core::Time,
                                          std::pair<RNGine::Core::Time,
                                                    std::pair<float, float>>>>>(
              {
                  true,
                  {{1, std::make_pair(1500.0f, std::make_pair(-700.0f, 0.0f))}},
              })},
         {"hitboxWidth", 64 * 1.8f},
         {"hitboxHeight", 46 * 1.8f},
         {"originX", 0.0f},
         {"originY", 0.0f},
         {"attackableHealth", 100.0f},
         {"attackableScore", 100.0f},
         {"enemyShootRate", 1000.0f},
         {"velocityShoot", std::pair<float, float>(-700.0f, 0.0f)},
         {"destroyPositionShoot", std::pair<float, float>(-100.0f, 2020.0f)},
         {"offsetPositionShoot", std::pair<float, float>(-32 * 1.8f, 0.0f)},
         {"scaleShoot", std::pair<float, float>(3.0f, 3.0f)},
         {"hitboxFirst", std::pair<float, float>(32 * 3.0f, 33 * 3.0f)},
         {"hitboxSecond", std::pair<float, float>(0.0f, 0.0f)},
         {"damages", 50.0f},
         {"collider", std::pair<bool, RNGine::Addons::CollisionAction>(
                          false, RNGine::Addons::CollisionAction::None)},
         {"colliderShoot",
          std::pair<bool, RNGine::Addons::CollisionAction>(
              false, RNGine::Addons::CollisionAction::Explosion)}}, // DESIGN
        {{"enemySpritePath", "./assets/enemies2.png"},
         {"bulletSpritePath", "./assets/bullets2.png"},
         {"bulletShootSound", "./assets/sounds/bullet.mp3"},
         {"bulletShootSoundVolume", 50.0f},
         {"spriteBulletRect", std::map<std::string, float>{{"x", 33 * 4.0f},
                                                           {"y", 17.0f},
                                                           {"width", 33.0f},
                                                           {"height", 33.0f}}},
         {"bulletAnimation",
          std::map<std::string, shootAnimationValue>{
              {"reverse", true},
              {"loop", false},
              {"multiple", true},
              {"finish", false},
              {"start", std::pair<int, int>(8, 0)},
              {"end", std::pair<int, int>(11, 0)},
              {"lastFrame", std::pair<int, int>(7, 0)},
              {"frequence", (RNGine::Core::Time)150}}},
         {"zIndex", 10},
         {"spriteRect", std::map<std::string, float>{{"x", 4.0f * 64.0f},
                                                     {"y", 0.0f},
                                                     {"width", 64.0f},
                                                     {"height", 46.0f}}},
         {"spriteAnimation",
          std::map<std::string, spriteAnimationValue>{{"reverse", false},
                                                      {"looping", true},
                                                      {"multiple", true},
                                                      {"startFrame", 0},
                                                      {"endFrame", 3},
                                                      {"stopFrame", 0},
                                                      {"frequence", 300},
                                                      {"lastUpdate", 0}}}}};

const std::pair<std::map<std::string, ValueFirstMap>,
                std::map<std::string, Value>>
    ENEMY_TYPE_3 = {
        {{"width", 1.8f},
         {"height", 1.8f},
         {"velocityX", -300.0f},
         {"velocityY", -200.0f},
         {"positionMob", -1.0f},
         {"winCondition", 0.0f},
         {"makeDamages", 50.0f},
         {"movementPattern",
          std::pair<
              int,
              std::pair<bool, std::vector<std::pair<RNGine::Core::Time,
                                                    std::pair<float, float>>>>>(
              {0,
               {
                   true,
                   {{RNGine::Core::Time(1), std::make_pair(-300.0f, -200.0f)},
                    {RNGine::Core::Time(1), std::make_pair(-300.0f, 200.0f)}},
               }})},
         {"shootPattern",
          std::pair<bool,
                    std::vector<std::pair<RNGine::Core::Time,
                                          std::pair<RNGine::Core::Time,
                                                    std::pair<float, float>>>>>(
              {
                  true,
                  {{RNGine::Core::Time(1),
                    std::make_pair(3000.0f, std::make_pair(-150.0f, 0.0f))}},
              })},
         {"hitboxWidth", 68.8f * 1.8f},
         {"hitboxHeight", 44 * 1.8f},
         {"originX", 0.0f},
         {"originY", 0.0f},
         {"attackableHealth", 1.0f},
         {"attackableScore", 25.0f},
         {"enemyShootRate", 900.0f},
         {"velocityShoot", std::pair<float, float>(-150.0f, 0.0f)},
         {"destroyPositionShoot", std::pair<float, float>(-100.0f, 2020.0f)},
         {"offsetPositionShoot", std::pair<float, float>(40.0f, 20.0f)},
         {"scaleShoot", std::pair<float, float>(0.5f, 0.5f)},
         {"hitboxFirst", std::pair<float, float>(96.33f * 0.5f, 136.0f * 0.5f)},
         {"hitboxSecond", std::pair<float, float>(0.0f, 0.0f)},
         {"damages", 150.0f},
         {"collider", std::pair<bool, RNGine::Addons::CollisionAction>(
                          false, RNGine::Addons::CollisionAction::None)},
         {"colliderShoot",
          std::pair<bool, RNGine::Addons::CollisionAction>(
              false, RNGine::Addons::CollisionAction::Explosion)}}, // DESIGN
        {{"enemySpritePath", "./assets/bombershipEnemy.png"},
         {"bulletSpritePath", "./assets/bomb.png"},
         {"bulletShootSound", "./assets/sounds/bullet.mp3"}, // a changer
         {"bulletShootSoundVolume", 50.0f},
         {"spriteBulletRect", std::map<std::string, float>{{"x", 96.33f * 3.0f},
                                                           {"y", 0.0f},
                                                           {"width", 96.33f},
                                                           {"height", 136.0f}}},
         {"bulletAnimation",
          std::map<std::string, shootAnimationValue>{
              {"reverse", false},
              {"loop", false},
              {"multiple", false},
              {"finish", false},
              {"start", std::pair<int, int>(0, 0)},
              {"end", std::pair<int, int>(2, 0)},
              {"lastFrame", std::pair<int, int>(2, 0)},
              {"frequence", (RNGine::Core::Time)300}}},
         {"zIndex", 10},
         {"spriteRect", std::map<std::string, float>{{"x", 6.0f * 68.8f},
                                                     {"y", 0.0f},
                                                     {"width", 68.8f},
                                                     {"height", 44.0f}}},
         {"spriteAnimation",
          std::map<std::string, spriteAnimationValue>{{"reverse", false},
                                                      {"looping", true},
                                                      {"multiple", true},
                                                      {"startFrame", 0},
                                                      {"endFrame", 5},
                                                      {"stopFrame", 0},
                                                      {"frequence", 200},
                                                      {"lastUpdate", 0}}}}};

const std::pair<std::map<std::string, ValueFirstMap>,
                std::map<std::string, Value>>
    ENEMY_TYPE_4 = {
        {{"width", 2.0f},
         {"height", 2.0f},
         {"velocityX", -400.0f},
         {"velocityY", 0.0f},
         {"positionMob", -1.0f},
         {"winCondition", 0.0f},
         {"makeDamages", 0.0f},
         {"movementPattern",
          std::pair<
              int,
              std::pair<bool, std::vector<std::pair<RNGine::Core::Time,
                                                    std::pair<float, float>>>>>(
              {0,
               {
                   false,
                   {{0, std::make_pair(0.0f, 0.0f)}},
               }})},
         {"shootPattern",
          std::pair<
              bool,
              std::vector<std::pair<
                  RNGine::Core::Time,
                  std::pair<RNGine::Core::Time, std::pair<float, float>>>>>({
              true,
              {
                  {RNGine::Core::Time(1),
                   std::make_pair(200.0f, std::make_pair(-700.0f, 100.0f))},
                  {RNGine::Core::Time(2),
                   std::make_pair(200.0f, std::make_pair(-700.0f, -100.0f))},
              },
          })},
         {"hitboxWidth", 61.4f * 2.0f},
         {"hitboxHeight", (59.0f * 2.0f) - 30.0f},
         {"originX", 0.0f},
         {"originY", 0.0f},
         {"attackableHealth", 50.0f},
         {"attackableScore", 100.0f},
         {"enemyShootRate", 200.0f},
         {"velocityShoot", std::pair<float, float>(-700.0f, 100.0f)},
         {"destroyPositionShoot", std::pair<float, float>(-100.0f, 2020.0f)},
         {"offsetPositionShoot", std::pair<float, float>(-20.0f, 10.0f)},
         {"scaleShoot", std::pair<float, float>(4.0f, 4.0f)},
         {"hitboxFirst", std::pair<float, float>(24.0f * 4.0f, 24.0f * 4.0f)},
         {"hitboxSecond", std::pair<float, float>(0.0f, 0.0f)},
         {"damages", 25.0f},
         {"collider", std::pair<bool, RNGine::Addons::CollisionAction>(
                          false, RNGine::Addons::CollisionAction::None)},
         {"colliderShoot",
          std::pair<bool, RNGine::Addons::CollisionAction>(
              false, RNGine::Addons::CollisionAction::Explosion)}},
        {{"enemySpritePath", "./assets/dragon.png"},
         {"bulletSpritePath", "./assets/dragonFire.png"},
         {"bulletShootSound", "./assets/sounds/bullet.wav"},
         {"bulletShootSoundVolume", 50.0f},
         {"spriteBulletRect",
          std::map<std::string, float>{
              {"x", 0.0f}, {"y", 0.0f}, {"width", 24.0f}, {"height", 24.0f}}},
         {"bulletAnimation",
          std::map<std::string, shootAnimationValue>{
              {"reverse", false},
              {"loop", true},
              {"multiple", true},
              {"finish", false},
              {"start", std::pair<int, int>(0, 0)},
              {"end", std::pair<int, int>(59, 0)},
              {"lastFrame", std::pair<int, int>(59, 0)},
              {"frequence", (RNGine::Core::Time)50}}},
         {"zIndex", 10},
         {"spriteRect", std::map<std::string, float>{{"x", 5.0f * 61.4f},
                                                     {"y", 5.0f},
                                                     {"width", 61.4f},
                                                     {"height", 59.0f}}},
         {"spriteAnimation",
          std::map<std::string, spriteAnimationValue>{{"reverse", false},
                                                      {"looping", true},
                                                      {"multiple", true},
                                                      {"startFrame", 0},
                                                      {"endFrame", 4},
                                                      {"stopFrame", 0},
                                                      {"frequence", 150},
                                                      {"lastUpdate", 0}}}}};

const std::pair<std::map<std::string, ValueFirstMap>,
                std::map<std::string, Value>>
    BOSS_TYPE_1 = {
        {{"width", 3.0f},
         {"height", 3.0f},
         {"velocityX", -500.0f},
         {"velocityY", 0.0f},
         {"positionMob", 250.0f},
         {"winCondition", 1.0f},
         {"makeDamages", 100.0f},
         {"movementPattern",
          std::pair<
              int,
              std::pair<bool, std::vector<std::pair<RNGine::Core::Time,
                                                    std::pair<float, float>>>>>(
              {1,
               {
                   true,
                   {{RNGine::Core::Time(1), std::make_pair(-100.0f, 0.0f)},
                    {RNGine::Core::Time(1), std::make_pair(0.0f, -200.0f)},
                    {RNGine::Core::Time(1), std::make_pair(0.0f, 400.0f)},
                    {RNGine::Core::Time(1), std::make_pair(0.0f, -200.0f)},
                    {RNGine::Core::Time(0.75), std::make_pair(0.0f, 0.0f)}},
               }})},
         {"shootPattern",
          std::pair<
              bool,
              std::vector<std::pair<
                  RNGine::Core::Time,
                  std::pair<RNGine::Core::Time, std::pair<float, float>>>>>({
              false,
              {{1, std::make_pair(3000.0f, std::make_pair(-1000.0f, 0.0f))}},
          })},
         {"hitboxWidth", 160 * 3.0f},
         {"hitboxHeight", 212.25f * 3.0f},
         {"originX", 0.0f},
         {"originY", 0.0f},
         {"attackableHealth", 20000.0f},
         {"attackableScore", 1000.0f},
         {"enemyShootRate", 2250.0f},
         {"velocityShoot", std::pair<float, float>(-1000.0f, 0.0f)},
         {"destroyPositionShoot", std::pair<float, float>(-100.0f, 2020.0f)},
         {"offsetPositionShoot", std::pair<float, float>(-50.0f, 200.0f)},
         {"scaleShoot", std::pair<float, float>(10.0f, 10.0f)},
         {"hitboxFirst", std::pair<float, float>(23.0f * 10.0f, 20.0f * 10.0f)},
         {"hitboxSecond", std::pair<float, float>(0.0f, 0.0f)},
         {"damages", 100.0f},
         {"collider", std::pair<bool, RNGine::Addons::CollisionAction>(
                          false, RNGine::Addons::CollisionAction::None)},
         {"colliderShoot",
          std::pair<bool, RNGine::Addons::CollisionAction>(
              false, RNGine::Addons::CollisionAction::Explosion)}}, // DESIGN
        {{"enemySpritePath", "./assets/boss_level1.png"},
         {"bulletSpritePath", "./assets/bullet_boss_level1.png"},
         {"bulletShootSound", "./assets/sounds/bullet.mp3"},
         {"bulletShootSoundVolume", 50.0f},
         {"spriteBulletRect",
          std::map<std::string, float>{
              {"x", 0.0f}, {"y", 0.0f}, {"width", 23.0f}, {"height", 20.0f}}},
         {"bulletAnimation",
          std::map<std::string, shootAnimationValue>{
              {"reverse", true},
              {"loop", false},
              {"multiple", true},
              {"finish", false},
              {"start", std::pair<int, int>(0, 0)},
              {"end", std::pair<int, int>(3, 0)},
              {"lastFrame", std::pair<int, int>(0, 0)},
              {"frequence", (RNGine::Core::Time)100}}},
         {"zIndex", 10},
         {"spriteRect", std::map<std::string, float>{{"x", 0.0f},
                                                     {"y", 0.0f},
                                                     {"width", 160.0f},
                                                     {"height", 212.25f}}},
         {"spriteAnimation",
          std::map<std::string, spriteAnimationValue>{{"reverse", true},
                                                      {"looping", true},
                                                      {"multiple", true},
                                                      {"startFrame", 0},
                                                      {"endFrame", 7},
                                                      {"stopFrame", 0},
                                                      {"frequence", 150},
                                                      {"lastUpdate", 0}}}}};

const std::pair<std::map<std::string, ValueFirstMap>,
                std::map<std::string, Value>>
    BOSS_TYPE_2_HEAD = {
        {{"width", 5.0f},
         {"height", 6.0f},
         {"velocityX", -300.0f},
         {"velocityY", 0.0f},
         {"positionMob", 100.0f},
         {"winCondition", 0.0f},
         {"makeDamages", 100.0f},
         {"movementPattern",
          std::pair<
              int,
              std::pair<bool, std::vector<std::pair<RNGine::Core::Time,
                                                    std::pair<float, float>>>>>(
              {2,
               {
                   true,
                   {
                       {0.5, std::make_pair(-300.0f, 100.0f)},
                       {0.5, std::make_pair(-300.0f, -100.0f)},
                       {0.5, std::make_pair(-300.0f, 100.0f)},
                       {0.5, std::make_pair(-300.0f, -100.0f)},
                       {0.5, std::make_pair(-300.0f, 100.0f)},
                       {0.5, std::make_pair(-300.0f, -100.0f)},
                       {0.5, std::make_pair(-300.0f, 100.0f)},
                       {0.5, std::make_pair(-300.0f, -100.0f)},
                       {0.5, std::make_pair(-300.0f, 100.0f)},
                       {0.5, std::make_pair(-300.0f, -100.0f)},
                       {0.5, std::make_pair(-300.0f, 100.0f)},
                       {0.5, std::make_pair(-300.0f, -100.0f)},
                       {5, std::make_pair(140.0f, 150.0f)},
                       {2, std::make_pair(-350.0f, 0.0f)},
                       {5, std::make_pair(0.0f, -150.0f)},
                       {0.5, std::make_pair(300.0f, 100.0f)},
                       {0.5, std::make_pair(300.0f, -100.0f)},
                       {0.5, std::make_pair(300.0f, 100.0f)},
                       {0.5, std::make_pair(300.0f, -100.0f)},
                       {0.5, std::make_pair(300.0f, 100.0f)},
                       {0.5, std::make_pair(300.0f, -100.0f)},
                       {0.5, std::make_pair(300.0f, 100.0f)},
                       {0.5, std::make_pair(300.0f, -100.0f)},
                       {0.5, std::make_pair(300.0f, 100.0f)},
                       {0.5, std::make_pair(300.0f, -100.0f)},
                       {5, std::make_pair(0.0f, 150.0f)},
                       {0.5, std::make_pair(-300.0f, 100.0f)},
                       {0.5, std::make_pair(-300.0f, -100.0f)},
                       {0.5, std::make_pair(-300.0f, 100.0f)},
                       {0.5, std::make_pair(-300.0f, -100.0f)},
                       {0.5, std::make_pair(-300.0f, 100.0f)},
                       {0.5, std::make_pair(-300.0f, -100.0f)},
                       {0.5, std::make_pair(-300.0f, 100.0f)},
                       {0.5, std::make_pair(-300.0f, -100.0f)},
                       {0.5, std::make_pair(-300.0f, 100.0f)},
                       {0.5, std::make_pair(-300.0f, -100.0f)},
                       {5, std::make_pair(140.0f, -150.0f)},
                       {2, std::make_pair(-350.0f, 0.0f)},
                       {5, std::make_pair(0.0f, 150.0f)},
                       {0.5, std::make_pair(300.0f, -140.0f)},
                       {0.5, std::make_pair(300.0f, -140.0f)},
                       {0.5, std::make_pair(300.0f, -140.0f)},
                       {0.5, std::make_pair(300.0f, -140.0f)},
                       {0.5, std::make_pair(300.0f, -140.0f)},
                       {0.5, std::make_pair(300.0f, -140.0f)},
                       {0.5, std::make_pair(300.0f, -140.0f)},
                       {0.5, std::make_pair(300.0f, -140.0f)},
                       {0.5, std::make_pair(300.0f, -140.0f)},
                       {0.5, std::make_pair(300.0f, -140.0f)},
                   },
               }})},
         {"shootPattern",
          std::pair<
              bool,
              std::vector<std::pair<
                  RNGine::Core::Time,
                  std::pair<RNGine::Core::Time, std::pair<float, float>>>>>({
              false,
              {{1, std::make_pair(3000.0f, std::make_pair(-1000.0f, 0.0f))}},
          })},
         {"hitboxWidth", 32 * 5.0f},
         {"hitboxHeight", 30 * 6.0f},
         {"originX", 0.0f},
         {"originY", 0.0f},
         {"attackableHealth", 10000.0f},
         {"attackableScore", 1000.0f},
         {"enemyShootRate", 100000000.0f},
         {"velocityShoot", std::pair<float, float>(-1000.0f, 0.0f)},
         {"destroyPositionShoot", std::pair<float, float>(-100.0f, 2020.0f)},
         {"offsetPositionShoot", std::pair<float, float>(-50.0f, 200.0f)},
         {"scaleShoot", std::pair<float, float>(10.0f, 10.0f)},
         {"hitboxFirst", std::pair<float, float>(32.0f * 10.0f, 30.0f * 10.0f)},
         {"hitboxSecond", std::pair<float, float>(0.0f, 0.0f)},
         {"damages", 0.0f},
         {"collider", std::pair<bool, RNGine::Addons::CollisionAction>(
                          false, RNGine::Addons::CollisionAction::None)},
         {"colliderShoot",
          std::pair<bool, RNGine::Addons::CollisionAction>(
              false, RNGine::Addons::CollisionAction::Explosion)}}, // DESIGN
        {{"enemySpritePath", "./assets/boss_level2.png"},
         {"bulletSpritePath", "./assets/bullet_boss_level1.png"},
         {"bulletShootSound", "./assets/sounds/bullet.mp3"},
         {"bulletShootSoundVolume", 50.0f},
         {"spriteBulletRect",
          std::map<std::string, float>{
              {"x", 0.0f}, {"y", 0.0f}, {"width", 23.0f}, {"height", 20.0f}}},
         {"bulletAnimation",
          std::map<std::string, shootAnimationValue>{
              {"reverse", true},
              {"loop", false},
              {"multiple", true},
              {"finish", false},
              {"start", std::pair<int, int>(0, 0)},
              {"end", std::pair<int, int>(3, 0)},
              {"lastFrame", std::pair<int, int>(0, 0)},
              {"frequence", (RNGine::Core::Time)100}}},
         {"zIndex", 10},
         {"spriteRect",
          std::map<std::string, float>{
              {"x", 0.0f}, {"y", 0.0f}, {"width", 32.0f}, {"height", 30.0f}}},
         {"spriteAnimation", std::map<std::string, spriteAnimationValue>{
                                 {"reverse", false},
                                 {"looping", false},
                                 {"multiple", true},
                                 {"startFrame", 0},
                                 {"endFrame", 3},
                                 {"stopFrame", 0},
                                 {"frequence", 300},
                                 {"lastUpdate", 0}}}}};

const std::pair<std::map<std::string, ValueFirstMap>,
                std::map<std::string, Value>>
    BOSS_TYPE_2_BODY = {
        {{"width", 5.0f},
         {"height", 6.0f},
         {"velocityX", -300.0f},
         {"velocityY", 0.0f},
         {"positionMob", 100.0f},
         {"winCondition", 0.0f},
         {"makeDamages", 50.0f},
         {"movementPattern",
          std::pair<
              int,
              std::pair<bool, std::vector<std::pair<RNGine::Core::Time,
                                                    std::pair<float, float>>>>>(
              {2,
               {
                   true,
                   {
                       {0.5, std::make_pair(-300.0f, 100.0f)},
                       {0.5, std::make_pair(-300.0f, -100.0f)},
                       {0.5, std::make_pair(-300.0f, 100.0f)},
                       {0.5, std::make_pair(-300.0f, -100.0f)},
                       {0.5, std::make_pair(-300.0f, 100.0f)},
                       {0.5, std::make_pair(-300.0f, -100.0f)},
                       {0.5, std::make_pair(-300.0f, 100.0f)},
                       {0.5, std::make_pair(-300.0f, -100.0f)},
                       {0.5, std::make_pair(-300.0f, 100.0f)},
                       {0.5, std::make_pair(-300.0f, -100.0f)},
                       {0.5, std::make_pair(-300.0f, 100.0f)},
                       {0.5, std::make_pair(-300.0f, -100.0f)},
                       {5, std::make_pair(140.0f, 150.0f)},
                       {2, std::make_pair(-350.0f, 0.0f)},
                       {5, std::make_pair(0.0f, -150.0f)},
                       {0.5, std::make_pair(300.0f, 100.0f)},
                       {0.5, std::make_pair(300.0f, -100.0f)},
                       {0.5, std::make_pair(300.0f, 100.0f)},
                       {0.5, std::make_pair(300.0f, -100.0f)},
                       {0.5, std::make_pair(300.0f, 100.0f)},
                       {0.5, std::make_pair(300.0f, -100.0f)},
                       {0.5, std::make_pair(300.0f, 100.0f)},
                       {0.5, std::make_pair(300.0f, -100.0f)},
                       {0.5, std::make_pair(300.0f, 100.0f)},
                       {0.5, std::make_pair(300.0f, -100.0f)},
                       {5, std::make_pair(0.0f, 150.0f)},
                       {0.5, std::make_pair(-300.0f, 100.0f)},
                       {0.5, std::make_pair(-300.0f, -100.0f)},
                       {0.5, std::make_pair(-300.0f, 100.0f)},
                       {0.5, std::make_pair(-300.0f, -100.0f)},
                       {0.5, std::make_pair(-300.0f, 100.0f)},
                       {0.5, std::make_pair(-300.0f, -100.0f)},
                       {0.5, std::make_pair(-300.0f, 100.0f)},
                       {0.5, std::make_pair(-300.0f, -100.0f)},
                       {0.5, std::make_pair(-300.0f, 100.0f)},
                       {0.5, std::make_pair(-300.0f, -100.0f)},
                       {5, std::make_pair(140.0f, -150.0f)},
                       {2, std::make_pair(-350.0f, 0.0f)},
                       {5, std::make_pair(0.0f, 150.0f)},
                       {0.5, std::make_pair(300.0f, -140.0f)},
                       {0.5, std::make_pair(300.0f, -140.0f)},
                       {0.5, std::make_pair(300.0f, -140.0f)},
                       {0.5, std::make_pair(300.0f, -140.0f)},
                       {0.5, std::make_pair(300.0f, -140.0f)},
                       {0.5, std::make_pair(300.0f, -140.0f)},
                       {0.5, std::make_pair(300.0f, -140.0f)},
                       {0.5, std::make_pair(300.0f, -140.0f)},
                       {0.5, std::make_pair(300.0f, -140.0f)},
                       {0.5, std::make_pair(300.0f, -140.0f)},
                   },
               }})},
         {"shootPattern",
          std::pair<
              bool,
              std::vector<std::pair<
                  RNGine::Core::Time,
                  std::pair<RNGine::Core::Time, std::pair<float, float>>>>>({
              false,
              {{1, std::make_pair(3000.0f, std::make_pair(-1000.0f, 0.0f))}},
          })},
         {"hitboxWidth", 16 * 5.0f},
         {"hitboxHeight", 30 * 6.0f},
         {"originX", 0.0f},
         {"originY", 0.0f},
         {"attackableHealth", 10000.0f},
         {"attackableScore", 1000.0f},
         {"enemyShootRate", 100000.0f},
         {"velocityShoot", std::pair<float, float>(-1000.0f, 0.0f)},
         {"destroyPositionShoot", std::pair<float, float>(-100.0f, 2020.0f)},
         {"offsetPositionShoot", std::pair<float, float>(-50.0f, 200.0f)},
         {"scaleShoot", std::pair<float, float>(10.0f, 10.0f)},
         {"hitboxFirst", std::pair<float, float>(16.0f * 5.0f, 30.0f * 6.0f)},
         {"hitboxSecond", std::pair<float, float>(0.0f, 0.0f)},
         {"damages", 0.0f},
         {"collider", std::pair<bool, RNGine::Addons::CollisionAction>(
                          false, RNGine::Addons::CollisionAction::None)},
         {"colliderShoot",
          std::pair<bool, RNGine::Addons::CollisionAction>(
              false, RNGine::Addons::CollisionAction::Explosion)}}, // DESIGN
        {{"enemySpritePath", "./assets/boss_level2.png"},
         {"bulletSpritePath", "./assets/bullet_boss_level1.png"},
         {"bulletShootSound", "./assets/sounds/bullet.mp3"},
         {"bulletShootSoundVolume", 50.0f},
         {"spriteBulletRect",
          std::map<std::string, float>{
              {"x", 0.0f}, {"y", 0.0f}, {"width", 23.0f}, {"height", 20.0f}}},
         {"bulletAnimation",
          std::map<std::string, shootAnimationValue>{
              {"reverse", true},
              {"loop", false},
              {"multiple", true},
              {"finish", false},
              {"start", std::pair<int, int>(0, 0)},
              {"end", std::pair<int, int>(3, 0)},
              {"lastFrame", std::pair<int, int>(0, 0)},
              {"frequence", (RNGine::Core::Time)100}}},
         {"zIndex", 10},
         {"spriteRect",
          std::map<std::string, float>{
              {"x", 128.0f}, {"y", 0.0f}, {"width", 16.0f}, {"height", 30.0f}}},
         {"spriteAnimation", std::map<std::string, spriteAnimationValue>{
                                 {"reverse", false},
                                 {"looping", false},
                                 {"multiple", false},
                                 {"startFrame", 8},
                                 {"endFrame", 8},
                                 {"stopFrame", 8},
                                 {"frequence", 300},
                                 {"lastUpdate", 0}}}}};

const std::pair<std::map<std::string, ValueFirstMap>,
                std::map<std::string, Value>>
    BOSS_TYPE_3_BODY = {
        {{"width", 5.0f},
         {"height", 6.0f},
         {"velocityX", -300.0f},
         {"velocityY", 0.0f},
         {"positionMob", 1080.0f},
         {"winCondition", 0.0f},
         {"makeDamages", 0.0f},
         {"movementPattern",
          std::pair<
              int,
              std::pair<bool, std::vector<std::pair<RNGine::Core::Time,
                                                    std::pair<float, float>>>>>(
              {0,
               {
                   false,
                   {{RNGine::Core::Time(1), std::make_pair(-300.0f, 0.0f)},
                    {RNGine::Core::Time(3), std::make_pair(0.0f, -550.0f)},
                    {RNGine::Core::Time(1), std::make_pair(0.0f, 0.0f)}},
               }})},
         {"shootPattern",
          std::pair<
              bool,
              std::vector<std::pair<
                  RNGine::Core::Time,
                  std::pair<RNGine::Core::Time, std::pair<float, float>>>>>({
              false,
              {{1, std::make_pair(3000.0f, std::make_pair(-1000.0f, 0.0f))}},
          })},
         {"hitboxWidth", 56 * 5.0f},
         {"hitboxHeight", 296 * 6.0f},
         {"originX", 0.0f},
         {"originY", 0.0f},
         {"attackableHealth", 100000.0f},
         {"attackableScore", 1000.0f},
         {"enemyShootRate", 50000.0f},
         {"velocityShoot", std::pair<float, float>(-1000.0f, 0.0f)},
         {"destroyPositionShoot", std::pair<float, float>(-100.0f, 2020.0f)},
         {"offsetPositionShoot", std::pair<float, float>(-50.0f, 200.0f)},
         {"scaleShoot", std::pair<float, float>(10.0f, 10.0f)},
         {"hitboxFirst", std::pair<float, float>(23.0f * 10.0f, 20.0f * 10.0f)},
         {"hitboxSecond", std::pair<float, float>(0.0f, 0.0f)},
         {"damages", 100.0f},
         {"collider", std::pair<bool, RNGine::Addons::CollisionAction>(
                          true, RNGine::Addons::CollisionAction::PushingForce)},
         {"colliderShoot",
          std::pair<bool, RNGine::Addons::CollisionAction>(
              false, RNGine::Addons::CollisionAction::Explosion)}}, // DESIGN
        {{"enemySpritePath", "./assets/boss_level3_body.png"},
         {"bulletSpritePath", "./assets/bullet_boss_level1.png"},
         {"bulletShootSound", "./assets/sounds/bullet.mp3"},
         {"bulletShootSoundVolume", 50.0f},
         {"spriteBulletRect",
          std::map<std::string, float>{
              {"x", 0.0f}, {"y", 0.0f}, {"width", 23.0f}, {"height", 20.0f}}},
         {"bulletAnimation",
          std::map<std::string, shootAnimationValue>{
              {"reverse", true},
              {"loop", false},
              {"multiple", true},
              {"finish", false},
              {"start", std::pair<int, int>(0, 0)},
              {"end", std::pair<int, int>(3, 0)},
              {"lastFrame", std::pair<int, int>(0, 0)},
              {"frequence", (RNGine::Core::Time)100}}},
         {"zIndex", 10},
         {"spriteRect",
          std::map<std::string, float>{
              {"x", 0.0f}, {"y", 0.0f}, {"width", 56.0f}, {"height", 296.0f}}},
         {"spriteAnimation", std::map<std::string, spriteAnimationValue>{
                                 {"reverse", false},
                                 {"looping", false},
                                 {"multiple", false},
                                 {"startFrame", 0},
                                 {"endFrame", 1},
                                 {"stopFrame", 0},
                                 {"frequence", 300},
                                 {"lastUpdate", 0}}}}};

const std::pair<std::map<std::string, ValueFirstMap>,
                std::map<std::string, Value>>
    BOSS_TYPE_3_1 = {
        {{"width", 4.0f},
         {"height", 4.0f},
         {"velocityX", -605.0f},
         {"velocityY", 0.0f},
         {"positionMob", 1800.0f},
         {"winCondition", 1.0f},
         {"makeDamages", 50.0f},
         {"movementPattern",
          std::pair<
              int,
              std::pair<bool, std::vector<std::pair<RNGine::Core::Time,
                                                    std::pair<float, float>>>>>(
              {0,
               {
                   false,
                   {{RNGine::Core::Time(1), std::make_pair(0.0f, 0.0f)},
                    {RNGine::Core::Time(3.5), std::make_pair(0.0f, -500.0f)},
                    {RNGine::Core::Time(1), std::make_pair(0.0f, 0.0f)}},
               }})},
         {"shootPattern",
          std::pair<
              bool,
              std::vector<std::pair<
                  RNGine::Core::Time,
                  std::pair<RNGine::Core::Time, std::pair<float, float>>>>>({
              false,
              {{1, std::make_pair(3000.0f, std::make_pair(-900.0f, 600.0f))}},
          })},
         {"hitboxWidth", 120 * 4.0f},
         {"hitboxHeight", 88 * 4.0f},
         {"originX", 0.0f},
         {"originY", 0.0f},
         {"attackableHealth", 5000.0f},
         {"attackableScore", 1000.0f},
         {"enemyShootRate", 1800.0f},
         {"velocityShoot", std::pair<float, float>(-900.0f, 600.0f)},
         {"destroyPositionShoot", std::pair<float, float>(-100.0f, 2020.0f)},
         {"offsetPositionShoot", std::pair<float, float>(-200.0f, 20.0f)},
         {"scaleShoot", std::pair<float, float>(10.0f, 10.0f)},
         {"hitboxFirst", std::pair<float, float>(42.0f * 10.0f, 21.0f * 10.0f)},
         {"hitboxSecond", std::pair<float, float>(0.0f, 0.0f)},
         {"damages", 100.0f},
         {"collider", std::pair<bool, RNGine::Addons::CollisionAction>(
                          false, RNGine::Addons::CollisionAction::None)},
         {"colliderShoot",
          std::pair<bool, RNGine::Addons::CollisionAction>(
              false, RNGine::Addons::CollisionAction::Explosion)}}, // DESIGN
        {{"enemySpritePath", "./assets/boss_level3.png"},
         {"bulletSpritePath", "./assets/bullet_boss_level3.png"},
         {"bulletShootSound", "./assets/sounds/bullet.mp3"},
         {"bulletShootSoundVolume", 50.0f},
         {"spriteBulletRect",
          std::map<std::string, float>{
              {"x", 0.0f}, {"y", 0.0f}, {"width", 42.0f}, {"height", 21.0f}}},
         {"bulletAnimation",
          std::map<std::string, shootAnimationValue>{
              {"reverse", true},
              {"loop", false},
              {"multiple", true},
              {"finish", false},
              {"start", std::pair<int, int>(0, 0)},
              {"end", std::pair<int, int>(5, 0)},
              {"lastFrame", std::pair<int, int>(0, 0)},
              {"frequence", (RNGine::Core::Time)100}}},
         {"zIndex", 9},
         {"spriteRect", std::map<std::string, float>{{"x", 120.0f},
                                                     {"y", 0.0f},
                                                     {"width", 120.0f},
                                                     {"height", 88.0f}}},
         {"spriteAnimation", std::map<std::string, spriteAnimationValue>{
                                 {"reverse", false},
                                 {"looping", false},
                                 {"multiple", true},
                                 {"startFrame", 0},
                                 {"endFrame", 8},
                                 {"stopFrame", 0},
                                 {"frequence", 200},
                                 {"lastUpdate", 0}}}}};

const std::pair<std::map<std::string, ValueFirstMap>,
                std::map<std::string, Value>>
    BOSS_TYPE_3_2 = {
        {{"width", 4.0f},
         {"height", 4.0f},
         {"velocityX", -605.0f},
         {"velocityY", 0.0f},
         {"positionMob", 1900.0f},
         {"winCondition", 1.0f},
         {"makeDamages", 50.0f},
         {"movementPattern",
          std::pair<
              int,
              std::pair<bool, std::vector<std::pair<RNGine::Core::Time,
                                                    std::pair<float, float>>>>>(
              {0,
               {
                   false,
                   {{RNGine::Core::Time(1), std::make_pair(0.0f, 0.0f)},
                    {RNGine::Core::Time(3), std::make_pair(0.0f, -500.0f)},
                    {RNGine::Core::Time(1), std::make_pair(0.0f, 0.0f)}},
               }})},
         {"shootPattern",
          std::pair<
              bool,
              std::vector<std::pair<
                  RNGine::Core::Time,
                  std::pair<RNGine::Core::Time, std::pair<float, float>>>>>({
              false,
              {{1, std::make_pair(3000.0f, std::make_pair(-1000.0f, 0.0f))}},
          })},
         {"hitboxWidth", 120 * 4.0f},
         {"hitboxHeight", 88 * 4.0f},
         {"originX", 0.0f},
         {"originY", 0.0f},
         {"attackableHealth", 5000.0f},
         {"attackableScore", 1000.0f},
         {"enemyShootRate", 1800.0f},
         {"velocityShoot", std::pair<float, float>(-1000.0f, 0.0f)},
         {"destroyPositionShoot", std::pair<float, float>(-100.0f, 2020.0f)},
         {"offsetPositionShoot", std::pair<float, float>(-200.0f, 20.0f)},
         {"scaleShoot", std::pair<float, float>(10.0f, 10.0f)},
         {"hitboxFirst", std::pair<float, float>(42.0f * 10.0f, 21.0f * 10.0f)},
         {"hitboxSecond", std::pair<float, float>(0.0f, 0.0f)},
         {"damages", 100.0f},
         {"collider", std::pair<bool, RNGine::Addons::CollisionAction>(
                          false, RNGine::Addons::CollisionAction::None)},
         {"colliderShoot",
          std::pair<bool, RNGine::Addons::CollisionAction>(
              false, RNGine::Addons::CollisionAction::Explosion)}}, // DESIGN
        {{"enemySpritePath", "./assets/boss_level3.png"},
         {"bulletSpritePath", "./assets/bullet_boss_level3.png"},
         {"bulletShootSound", "./assets/sounds/bullet.mp3"},
         {"bulletShootSoundVolume", 50.0f},
         {"spriteBulletRect",
          std::map<std::string, float>{
              {"x", 0.0f}, {"y", 0.0f}, {"width", 42.0f}, {"height", 21.0f}}},
         {"bulletAnimation",
          std::map<std::string, shootAnimationValue>{
              {"reverse", true},
              {"loop", false},
              {"multiple", true},
              {"finish", false},
              {"start", std::pair<int, int>(0, 0)},
              {"end", std::pair<int, int>(5, 0)},
              {"lastFrame", std::pair<int, int>(0, 0)},
              {"frequence", (RNGine::Core::Time)100}}},
         {"zIndex", 9},
         {"spriteRect",
          std::map<std::string, float>{
              {"x", 0.0f}, {"y", 0.0f}, {"width", 120.0f}, {"height", 88.0f}}},
         {"spriteAnimation", std::map<std::string, spriteAnimationValue>{
                                 {"reverse", false},
                                 {"looping", false},
                                 {"multiple", true},
                                 {"startFrame", 0},
                                 {"endFrame", 8},
                                 {"stopFrame", 0},
                                 {"frequence", 200},
                                 {"lastUpdate", 0}}}}};

const std::pair<std::map<std::string, ValueFirstMap>,
                std::map<std::string, Value>>
    BOSS_TYPE_3_3 = {
        {{"width", 4.0f},
         {"height", 4.0f},
         {"velocityX", -605.0f},
         {"velocityY", 0.0f},
         {"positionMob", 1800.0f},
         {"winCondition", 1.0f},
         {"makeDamages", 50.0f},
         {"movementPattern",
          std::pair<
              int,
              std::pair<bool, std::vector<std::pair<RNGine::Core::Time,
                                                    std::pair<float, float>>>>>(
              {0,
               {
                   false,
                   {{RNGine::Core::Time(1), std::make_pair(0.0f, 0.0f)},
                    {RNGine::Core::Time(2), std::make_pair(0.0f, -500.0f)},
                    {RNGine::Core::Time(1), std::make_pair(0.0f, 0.0f)}},
               }})},
         {"shootPattern",
          std::pair<
              bool,
              std::vector<std::pair<
                  RNGine::Core::Time,
                  std::pair<RNGine::Core::Time, std::pair<float, float>>>>>({
              false,
              {{1, std::make_pair(3000.0f, std::make_pair(-900.0f, -600.0f))}},
          })},
         {"hitboxWidth", 120 * 4.0f},
         {"hitboxHeight", 88 * 4.0f},
         {"originX", 0.0f},
         {"originY", 0.0f},
         {"attackableHealth", 5000.0f},
         {"attackableScore", 1000.0f},
         {"enemyShootRate", 1800.0f},
         {"velocityShoot", std::pair<float, float>(-900.0f, -600.0f)},
         {"destroyPositionShoot", std::pair<float, float>(-100.0f, 2020.0f)},
         {"offsetPositionShoot", std::pair<float, float>(-200.0f, 20.0f)},
         {"scaleShoot", std::pair<float, float>(10.0f, 10.0f)},
         {"hitboxFirst", std::pair<float, float>(42.0f * 10.0f, 21.0f * 10.0f)},
         {"hitboxSecond", std::pair<float, float>(0.0f, 0.0f)},
         {"damages", 100.0f},
         {"collider", std::pair<bool, RNGine::Addons::CollisionAction>(
                          false, RNGine::Addons::CollisionAction::None)},
         {"colliderShoot",
          std::pair<bool, RNGine::Addons::CollisionAction>(
              false, RNGine::Addons::CollisionAction::Explosion)}}, // DESIGN
        {{"enemySpritePath", "./assets/boss_level3.png"},
         {"bulletSpritePath", "./assets/bullet_boss_level3.png"},
         {"bulletShootSound", "./assets/sounds/bullet.mp3"},
         {"bulletShootSoundVolume", 50.0f},
         {"spriteBulletRect",
          std::map<std::string, float>{
              {"x", 0.0f}, {"y", 0.0f}, {"width", 42.0f}, {"height", 21.0f}}},
         {"bulletAnimation",
          std::map<std::string, shootAnimationValue>{
              {"reverse", true},
              {"loop", false},
              {"multiple", true},
              {"finish", false},
              {"start", std::pair<int, int>(0, 0)},
              {"end", std::pair<int, int>(5, 0)},
              {"lastFrame", std::pair<int, int>(0, 0)},
              {"frequence", (RNGine::Core::Time)100}}},
         {"zIndex", 9},
         {"spriteRect",
          std::map<std::string, float>{
              {"x", 0.0f}, {"y", 0.0f}, {"width", 120.0f}, {"height", 88.0f}}},
         {"spriteAnimation", std::map<std::string, spriteAnimationValue>{
                                 {"reverse", false},
                                 {"looping", false},
                                 {"multiple", true},
                                 {"startFrame", 0},
                                 {"endFrame", 8},
                                 {"stopFrame", 0},
                                 {"frequence", 200},
                                 {"lastUpdate", 0}}}}};

namespace Rtype {
namespace Addons {

struct EnemyCreationRequest {
  int id;
  float x;
  float y;
  std::pair<std::map<std::string, ValueFirstMap>, std::map<std::string, Value>>
      enemyInfo;
  std::string name;

  static EnemyCreationRequest
  createShipCreationRequest(int id, float x, float y,
                            std::pair<std::map<std::string, ValueFirstMap>,
                                      std::map<std::string, Value>>
                                enemyInfo,
                            std::string name);
};

struct EnemyFactory {
  std::vector<EnemyCreationRequest> creationRequests;
  std::vector<RNGine::Scene::Entity> ships;
  bool createdWave = false;
};

void EnemyFactorySystem(RNGine::Core &core);

std::pair<std::map<std::string, ValueFirstMap>, std::map<std::string, Value>>
getEntityTypeByString(std::string enemy);

std::string getEntityTypeString(std::pair<std::map<std::string, ValueFirstMap>,
                                          std::map<std::string, Value>>
                                    enemy);

}; // namespace Addons
} // namespace Rtype

#endif