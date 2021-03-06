// force assertions
#undef NDEBUG
#include <assert.h>
#include <inttypes.h>
#include <stdio.h>
#include "heartbeats-simple-classic.h"

static const uint64_t WINDOW_SIZE = 10;
static const char* LOGFILE = "heartbeat.log";
static const uint64_t ITERATIONS = 20;
static const uint64_t WORK = 1;
static const uint64_t ACCURACY = 1;

static void test_hbsc(void) {
  hbsc_ctx hb;
  assert(hbsc_init(&hb, WINDOW_SIZE, LOGFILE) == 0);
  assert(hbsc_get_hb(&hb));
  uint64_t i;
  for (i = 0; i < ITERATIONS; i++) {
    assert(hbsc(&hb, i, WORK) == 0);
  }
  assert(hbsc_finish(&hb) == 0);
}

static void test_hbsc_acc(void) {
  hbsc_acc_ctx hb;
  assert(hbsc_acc_init(&hb, WINDOW_SIZE, LOGFILE) == 0);
  assert(hbsc_acc_get_hb(&hb));
  uint64_t i;
  for (i = 0; i < ITERATIONS; i++) {
    assert(hbsc_acc(&hb, i, WORK, ACCURACY) == 0);
  }
  assert(hbsc_acc_finish(&hb) == 0);
}

static void test_hbsc_pow(void) {
  hbsc_pow_ctx hb;
  assert(hbsc_pow_init(&hb, WINDOW_SIZE, LOGFILE) == 0);
  assert(hbsc_pow_get_hb(&hb));
  uint64_t i;
  for (i = 0; i < ITERATIONS; i++) {
    assert(hbsc_pow(&hb, i, WORK) == 0);
  }
  assert(hbsc_pow_finish(&hb) == 0);
}

static void test_hbsc_acc_pow(void) {
  hbsc_acc_pow_ctx hb;
  assert(hbsc_acc_pow_init(&hb, WINDOW_SIZE, LOGFILE) == 0);
  assert(hbsc_acc_pow_get_hb(&hb));
  uint64_t i;
  for (i = 0; i < ITERATIONS; i++) {
    assert(hbsc_acc_pow(&hb, i, WORK, ACCURACY) == 0);
  }
  assert(hbsc_acc_pow_finish(&hb) == 0);
}

int main(void) {
  test_hbsc();
  test_hbsc_acc();
  test_hbsc_pow();
  test_hbsc_acc_pow();
  return 0;
}
