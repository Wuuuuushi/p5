#include <PriorityQueue.hpp>
#include <catch2/catch_amalgamated.hpp>

namespace {
namespace proj5 = shindler::ics46::project5;
// NOLINTBEGIN(cppcoreguidelines-avoid-magic-numbers,
// readability-magic-numbers)

// As always, this is a STARTING POINT of TEST_CASE( cases
// and is not an exhaustive set of TEST_CASE( cases.
// You should be sure to TEST_CASE( EVERY function of
// your priority queue as well as the Lewis Carroll puzzle.
TEST_CASE("PriorityQueue:CreateWithInsert3:ExpectFront3",
          "[Required][PriorityQueue]") {
    proj5::PriorityQueue<int> pqueue;
    pqueue.push(3);
    REQUIRE(pqueue.min() == 3);
}

TEST_CASE("PriorityQueue:CreateWithInsert3,5:ExpectFront3",
          "[Required][PriorityQueue]") {
    proj5::PriorityQueue<int> pqueue;
    pqueue.push(3);
    pqueue.push(5);
    REQUIRE(pqueue.min() == 3);
}

TEST_CASE("PriorityQueue:CreateWithInsert3,2:ExpectFront2",
          "[Required][PriorityQueue]") {
    proj5::PriorityQueue<int> pqueue;
    pqueue.push(3);
    pqueue.push(2);
    REQUIRE(pqueue.min() == 2);
}

TEST_CASE("PriorityQueue")
{
    proj5::PriorityQueue<std::string> pqueue;
    pqueue.push("DA");
    pqueue.push("BC");
    pqueue.push("A");
    REQUIRE(pqueue.size() == 3);
    REQUIRE(pqueue.min() == "A");
    pqueue.popMin();
    REQUIRE(pqueue.min() == "BC");
    pqueue.popMin();
    REQUIRE(pqueue.min() == "DA");




}

TEST_CASE("DUPES")
{
    proj5::PriorityQueue<int> pq;

    pq.push(5);
    pq.push(3);
    pq.push(8);
    pq.push(2);
    pq.push(3); // Inserting an equal value

    // Since 3 was inserted before 8, it should be dequeued before 8
    REQUIRE(pq.min() == 2);
    pq.popMin();
    REQUIRE(pq.min() == 3);
    pq.popMin();
    REQUIRE(pq.min() == 3);
    pq.popMin();
    REQUIRE(pq.min() == 5);
    pq.popMin();
    REQUIRE(pq.min() == 8);
    pq.popMin();

    REQUIRE(pq.empty());
}
// NOLINTEND

}  // namespace
