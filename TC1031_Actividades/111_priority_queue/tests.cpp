﻿
#define CATCH_CONFIG_MAIN  
#include "pqueue.h"

TEST_CASE( "Testing priority queue implementation", "[PriorityQueue]" ) {
	PriorityQueue<int> q1, q2;
	for (int i = 3; i > 0; i--) {
		q2.enqueue(i*2);
	}

	SECTION( "1: Putting an element at the back." ) {
		q1.enqueue(3);
		REQUIRE(strcmp(q1.toString().c_str(), "[3]") == 0);
		q2.enqueue(3);
		REQUIRE(strcmp(q2.toString().c_str(), "[2, 3, 4, 6]") == 0);
		q2.enqueue(5);
		REQUIRE(strcmp(q2.toString().c_str(), "[2, 3, 4, 5, 6]") == 0);
		q2.enqueue(1);
		REQUIRE(strcmp(q2.toString().c_str(), "[1, 2, 3, 4, 5, 6]") == 0);
		q2.enqueue(7);
		REQUIRE(strcmp(q2.toString().c_str(), "[1, 2, 3, 4, 5, 6, 7]") == 0);
	}

	SECTION( "2: Checking the front" ) {
		REQUIRE_THROWS_AS(q1.front(), NoSuchElement);

		int x = q2.front();
		REQUIRE(x == 2);
		REQUIRE(strcmp(q2.toString().c_str(), "[2, 4, 6]") == 0);
	}

	SECTION( "3: Removing the front" ) {
		REQUIRE_THROWS_AS(q1.dequeue(), NoSuchElement);

		q2.dequeue();
		REQUIRE(strcmp(q2.toString().c_str(), "[4, 6]") == 0);
	}

	SECTION( "4: Testing if the queue is empty." ) {
		REQUIRE(q1.empty() == true);
		REQUIRE(q2.empty() == false);
	}

	SECTION( "5: Testing to clear a queue." ) {
		q2.clear();
		REQUIRE(strcmp(q2.toString().c_str(), "[]") == 0);
	}
}
