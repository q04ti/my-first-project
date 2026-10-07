/*
  Starbie firmware foundation

  This is a hardware-independent skeleton for the planned Starbie device.
  It has not been compiled against a selected board package or tested on
  physical hardware. Add sensor/display libraries only after the modules
  and their electrical details have been verified.
*/

#include <Wire.h>

// ---------- Configuration ----------
const bool USE_DHT11 = true;

// ---------- Pin definitions ----------
const int I2C_SDA_PIN = 6;
const int I2C_SCL_PIN = 7;
const int DHT_PIN = 3;
const int BUTTON_ONE_PIN = 4;
const int BUTTON_TWO_PIN = 5;

// ---------- Display ----------
void initializeDisplay() {
  // TODO: Select and install a library after the exact OLED controller is verified.
}

void updateDisplay() {
  // TODO: Render the pet, menus, sensor values, and animations.
}

// ---------- Motion sensor ----------
void initializeMotionSensor() {
  // TODO: Verify the MPU6050 module, address, and library before initialization.
}

void readMotionSensor() {
  // TODO: Read motion data and convert it into pet events.
}

// ---------- Environment sensor ----------
void initializeEnvironmentSensor() {
  if (!USE_DHT11) {
    return;
  }

  // TODO: Verify DHT11 module/bare-sensor wiring and add the selected library.
}

void readEnvironmentSensor() {
  if (!USE_DHT11) {
    return;
  }

  // TODO: DHT11 reads will be added after electrical and library verification.
}

// ---------- Buttons ----------
void initializeButtons() {
  // Proposed active-low wiring: each switch connects its GPIO to GND.
  // TODO: Confirm the final schematic and debounce behavior.
  pinMode(BUTTON_ONE_PIN, INPUT_PULLUP);
  pinMode(BUTTON_TWO_PIN, INPUT_PULLUP);
}

void readButtons() {
  // TODO: Add debounced button events after the final input circuit is chosen.
}

// ---------- Pet state ----------
struct PetState {
  int mood;
  int energy;
  int temperature;
  int humidity;
  bool hasMotion;
};

PetState pet = {0, 100, 0, 0, false};

void updatePetState() {
  // TODO: Define the pet's state transitions and sensor-driven reactions.
}

// ---------- Menu ----------
void updateMenu() {
  // TODO: Define button navigation and menu screens.
}

// ---------- Animation ----------
void updateAnimation() {
  // TODO: Add custom sprites, frame timing, and effects.
}

// ---------- Setup ----------
void setup() {
  // TODO: Confirm the exact XIAO pin mapping before hardware bring-up.
  Serial.begin(115200);

  Wire.begin(I2C_SDA_PIN, I2C_SCL_PIN);
  initializeDisplay();
  initializeMotionSensor();
  initializeEnvironmentSensor();
  initializeButtons();
}

// ---------- Main loop ----------
void loop() {
  readButtons();
  readMotionSensor();
  readEnvironmentSensor();
  updatePetState();
  updateMenu();
  updateAnimation();
  updateDisplay();

  // TODO: Replace with a deliberate scheduler once timing requirements are known.
  delay(20);
}
