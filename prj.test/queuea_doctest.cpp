
#include <queuea/queuea.h>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

TEST_CASE("[queuea] - ctor") {
	auto que_def = QueueA();
	CHECK(que_def.IsEmpty());
}