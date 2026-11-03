#define CATCH_CONFIG_MAIN

#include <catch2/catch_test_macros.hpp>
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