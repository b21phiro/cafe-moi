#define CATCH_CONFIG_MAIN

#include <catch2/catch_test_macros.hpp>

#include "../src/ComponentsManager.h"
#include "../src/EntityManager.h"

// ========================================================================================
// Example
// ========================================================================================

TEST_CASE("Catch2 works", "[catch2]")
{
    REQUIRE(1 + 2 == 3);
};

// ========================================================================================
// EcS
// ========================================================================================
// ========================================================================================
// EntityManager
// ========================================================================================

TEST_CASE("Initializes vector of set maximum amount of entities with -1", "[EntityManager]")
{
    int maxAmount = 2;
    EntityManager entityManager(maxAmount);

    std::vector<int>& entities = entityManager.getAll();

    REQUIRE(std::size(entities) == 2);
    REQUIRE(entities[0] == -1);
    REQUIRE(entities[1] == -1);

};

TEST_CASE("Adding entities works", "[EntityManager]")
{
    int maxAmount = 2;
    EntityManager entityManager(maxAmount);
    Entity entity = entityManager.createEntity();
    entityManager.addEntity(entity);
    REQUIRE(entityManager.getEntity(entity) == entity);
}

TEST_CASE("Removing entities works", "[EntityManager]")
{
    int maxAmount = 2;
    EntityManager entityManager(maxAmount);
    Entity entity = entityManager.createEntity();
    entityManager.addEntity(entity);
    REQUIRE(entityManager.getEntity(entity) == entity);
    entityManager.removeEntity(entity);
    REQUIRE(entityManager.getEntity(entity) == -1);
    REQUIRE(std::size(entityManager.getAll()) == 2);
}

TEST_CASE("Overflow of entity stack resets it", "[EntityManager]")
{
    int maxAmount = 2;
    EntityManager entityManager(maxAmount);
    Entity entity1 = entityManager.createEntity();
    Entity entity2 = entityManager.createEntity();
    Entity entity3 = entityManager.createEntity();
    entityManager.addEntities({ entity1, entity2, entity3 });
    std::vector<Entity> entities = entityManager.getAll();
    REQUIRE(std::size(entities) == 2);
    REQUIRE(entities[0] == 2);
    REQUIRE(entities[1] == -1);
}

// ========================================================================================
// ComponentsManager
// ========================================================================================

TEST_CASE("Adding component to entity")
{
    int entity = 1;
    ComponentsManager componentsManager;
    componentsManager.addTag(entity, "Food");
    REQUIRE(componentsManager.hasTag(entity) == true);
}

TEST_CASE("Retrieving an entity´s component")
{
    int entityA = 0;
    int entityB = 1;
    int entityC = 2;

    ComponentsManager componentsManager;
    componentsManager.addTag(entityA, "Food");
    componentsManager.addTag(entityC, "Snack");
    componentsManager.addTag(entityB, "Beverage");

    REQUIRE(componentsManager.getTag(entityB).value == "Beverage");
    REQUIRE(componentsManager.getTag(entityC).value == "Snack");
    REQUIRE(componentsManager.getTag(entityA).value == "Food");
}

TEST_CASE("Removing an entity along with their component")
{
    int entityA = 0;
    int entityB = 1;

    ComponentsManager componentsManager;
    componentsManager.addTag(entityA, "Food");
    auto& tagB = componentsManager.addTag(entityB, "Beverage");

    componentsManager.removeEntity(entityB);
    REQUIRE(tagB.remove == true);
    componentsManager.update();
    REQUIRE(componentsManager.hasTag(entityA) == true);
    REQUIRE(componentsManager.hasTag(entityB) == false);
}
