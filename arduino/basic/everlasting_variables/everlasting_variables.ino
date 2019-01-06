//non-initialized value
union configUnion{
  uint8_t    byte[6]; // match the below struct...
  struct {
    uint16_t value1;
    uint16_t value2;
    uint16_t chksum;
  } val ;
} config    ;

void setup() {
  uint16_t sum; 
  //Initialize serial and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }

  // prints title with ending line break
  Serial.print("Out of Reset -");
  sum = getchksum();
  printValues();

  if (sum != config.val.chksum) {
    config.val.chksum = sum;
    Serial.print("chksum is incorrect setting config.val.chksum = 0x"); Serial.println(config.val.chksum, HEX);
  }

  config.val.value1++;
  config.val.value2++;
  Serial.print("setup new values - ");
  printValues();
  config.val.chksum = getchksum();
  Serial.print("updating chksum config.val.chksum = 0x"); Serial.println(config.val.chksum, HEX);
}

int counter = 0;

void loop() {
  if (counter < 200) {
    Serial.print("after a while - ");
    printValues();
    Serial.println();
    while (true) {
      continue;
    }
  }
  counter++;
}

void printValues() {
  Serial.print(" value1 = 0x"); Serial.print(config.val.value1, HEX);
  Serial.print(", value2 = 0x"); Serial.print(config.val.value2, HEX);
  Serial.print(", sum = 0x"); Serial.print(getchksum(), HEX);
  Serial.print(", chksum = 0x"); Serial.println(config.val.chksum, HEX);
}

uint16_t getchksum() {
  int sum = 0;
  for (int position = 0; position < (sizeof(config) - sizeof(config.val.chksum)); position++) {
    sum = sum + config.byte[position];
  }
  return sum;
}
