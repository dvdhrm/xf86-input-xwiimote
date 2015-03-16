#ifndef WIIMOTE
#define WIIMOTE

#include <xwiimote.h>

#include "key.h"
#include "ir.h"
#include "accelerometer.h"
#include "motionplus.h"

enum wiimote_key {
  WIIMOTE_KEY_LEFT,
  WIIMOTE_KEY_RIGHT,
  WIIMOTE_KEY_UP,
  WIIMOTE_KEY_DOWN,
  WIIMOTE_KEY_A,
  WIIMOTE_KEY_B,
  WIIMOTE_KEY_PLUS,
  WIIMOTE_KEY_MINUS,
  WIIMOTE_KEY_HOME,
  WIIMOTE_KEY_ONE,
  WIIMOTE_KEY_TWO,
  WIIMOTE_KEY_NUM
};


enum wiimote_motion_source {
  WIIMOTE_MOTION_SOURCE_NONE,
  WIIMOTE_MOTION_SOURCE_IR,
  WIIMOTE_MOTION_SOURCE_ACCELEROMETER,
  WIIMOTE_MOTION_SOURCE_MOTIONPLUS,
  WIIMOTE_MOTION_SOURCE_NUM
};

struct wiimote {
  struct key keys[WIIMOTE_KEY_NUM];
  struct ir ir;
  struct accelerometer accelerometer;
  struct motionplus motionplus;
};

struct wiimote_config {
  unsigned int motion_source;
  struct ir_config ir;
  struct accelerometer_config accelerometer;
  struct motionplus_config motionplus;
  struct key_config keys[WIIMOTE_KEY_NUM];
};

void close_wiimote(struct wiimote *wiimote);
void preinit_wiimote(struct wiimote_config *config);
void configure_wiimote(struct wiimote_config *config, char const * prefix, struct wiimote_config *defaults, InputInfoPtr info);

BOOL wiimote_ir_is_active(struct wiimote *wiimote, struct wiimote_config *config, struct xwii_event *ev);

void handle_wiimote_timer(struct wiimote *wiimote, struct wiimote_config *config, InputInfoPtr info);

void handle_wiimote_key_event(struct wiimote *wiimote, struct wiimote_config *config, struct xwii_event *ev, unsigned int state, InputInfoPtr info);
void handle_wiimote_ir_event(struct wiimote *wiimote, struct wiimote_config *config, struct xwii_event *ev, unsigned int state, InputInfoPtr info);
void handle_wiimote_motionplus_event(struct wiimote *wiimote, struct wiimote_config *config, struct xwii_event *ev, unsigned int state, InputInfoPtr info);
void handle_wiimote_accelerometer_event(struct wiimote *wiimote, struct wiimote_config *config, struct xwii_event *ev, unsigned int state, InputInfoPtr info);

unsigned int xwii_key_to_wiimote_key(unsigned int keycode, InputInfoPtr info);

#endif
