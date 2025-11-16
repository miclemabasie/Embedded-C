# Embedded Engineering Journey: ATtiny85 From Scratch
## *Bridging the Gap Between Silicon and Software*

This repository is a technical log of my journey into low-level embedded systems. I am focusing on the **AVR 8-bit architecture**, specifically the **ATtiny85**, to understand how **electrons flow through silicon**, how **logic gates are built from transistors**, and how **C code becomes voltage on a pin**.


## 🛠 Project Philosophy
* **Direct Register Manipulation:** No `digitalWrite()` or `pinMode()`. We talk to the hardware via memory-mapped I/O - because every assignment to `PORTB` is literally setting voltages on physical pins.
* **Datasheet-Driven Development:** Every implementation is based on the [Official ATtiny25/45/85 Datasheet](https://github.com/YOUR_USERNAME/YOUR_REPO/blob/main/Docs/Atmel-2586-ATtiny85-Datasheet.pdf) - your hardware's "bible."
* **Bare-Metal C:** Understanding how C statements become assembly, and assembly becomes silicon behavior.
* **Electronics First:** Before a register bit makes sense, understand the transistor, the pull-up resistor, and the current path.


## 🔌 Electronics Foundation (The Hardware Layer)

### Voltage Levels & Logic
```
ATtiny85 Operating Conditions:
┌─────────────────┬──────────┐
│ Parameter       │ Value    │
├─────────────────┼──────────┤
│ VCC (Operating) │ 1.8-5.5V │
│ VIL (Low Input) │ < 0.3VCC │
│ VIH (High Input)│ > 0.7VCC │
│ VOL (Low Output)│ < 0.7V   │
│ VOH (High Output)│ > VCC-0.7│
│ IOL (Sink Current)│ 10mA max │
│ IOH (Source)    │ 10mA max │
└─────────────────┴──────────┘
```

### The Pin Structure (What's REALLY inside)
```
                    ATtiny85 PIN INTERNAL STRUCTURE
                    ┌─────────────────────────────────┐
                    │                                 │
                    │   VCC ──┬── Pull-up Resistor   │
                    │         │    (20kΩ-50kΩ)       │
                    │         ▼                       │
        Data Bus ──┼──> D    Q ──┐                   │
                    │    Flip-Flop  │                   │
        Direction ──┼──> EN        ├──> Output Driver──┼──> PINx
                    │              │   (Push-Pull)     │
        PINx ───────┼──< Input     │                   │
                    │    Buffer    │                   │
                    └──────────────┴───────────────────┘
```

### Current Flow & External Components
```c
// LED Circuit Design (Ohm's Law in Practice)
// VCC = 5V, LED Vf = 2.0V, Desired Current = 10mA
// R = (VCC - Vf) / I = (5V - 2V) / 0.01A = 300Ω

// Why we need resistors:
// Without resistor: I = VCC / R(approx 0) = ∞ (BURN!)
// With resistor: Current limited to safe 10mA
```


## 🗺 Integrated Learning Roadmap (Hardware + Software)

### Phase 0: Electronics Fundamentals
* [ ] **Ohm's Law & Power:** V = IR, P = VI - The physics behind every circuit
* [ ] **LED Physics:** Forward voltage, current limiting, and why blue LEDs need different resistors than red
* [ ] **Switch Debouncing (Hardware):** RC time constants and Schmitt triggers
* [ ] **Microcontroller Power Supply:** Decoupling capacitors, voltage regulators, and noise filtering

### Phase 1: GPIO - Digital I/O (Software meets Silicon)
* [x] **Bitwise Mastery:** Understanding `&`, `|`, `~`, and `<<` for register masking
* [ ] **The "Big Three" I/O Registers:** 
  * `DDRB` - Data Direction Register (Controls the output driver's enable)
  * `PORTB` - Data Register (Sets the flip-flop's D input)
  * `PINB` - Input Pins Address (Reads the actual pin voltage)
* [ ] **Internal Pull-up Resistors:** 
  * **Hardware:** 20kΩ-50kΩ resistive path to VCC inside the chip
  * **Software:** Setting PORTBn = 1 when DDRBn = 0
* [ ] **Open-Drain vs Push-Pull:** Why some protocols need external pull-ups
* [ ] **Real Electronics:** Measuring pin voltage with a multimeter, observing signals on a scope

### Phase 2: Timing & Interrupts (The Heartbeat of Real-Time Systems)
* [ ] **Clock Sources:** 
  * Internal RC Oscillator (8MHz, but inaccurate)
  * External Crystal (Accurate, for precise timing)
  * PLL (Phase-Locked Loop for higher frequencies)
* [ ] **Hardware Timers (Timer0/Timer1):**
  * **Hardware:** Counters driven by clock ticks (like a digital stopwatch)
  * **Software:** Moving away from `_delay_ms()` (busy-wait) to non-blocking code
* [ ] **Interrupt Service Routines (ISR):**
  * **Hardware:** The CPU finishes current instruction, pushes context, jumps to vector
  * **Software:** Writing minimal, fast ISRs
* [ ] **PWM (Pulse Width Modulation):**
  * **Hardware:** Timer + Comparator automatically toggles pin
  * **Software:** Setting compare match values
  * **Electronics:** Averaging digital pulses into analog voltage

### Phase 3: Analog & Mixed-Signal
* [ ] **ADC (Analog to Digital Converter):**
  * **Hardware:** Successive approximation register (SAR) + sample & hold circuit
  * **Electronics:** Voltage divider for sensor interfacing, anti-aliasing filters
  * **Software:** 10-bit resolution = 1024 steps from 0 to VREF
* [ ] **Comparator:** The "1-bit ADC" for threshold detection
* [ ] **Brown-out Detection:** Protecting against undervoltage conditions

### Phase 4: Communication Protocols (The Digital Handshake)
* [ ] **USI (Universal Serial Interface):**
  * **Hardware:** Shift register + state machine
  * **Protocols:** Implementing $I^2C$ and SPI from the ground up
  * **Electronics:** Pull-up resistors on I2C, impedance matching on SPI
* [ ] **Timing Diagrams:** Reading oscilloscope patterns
* [ ] **Bus Contention:** What happens when two devices drive the same line?

### Phase 5: Advanced Hardware
* [ ] **Power Management:**
  * **Hardware:** Internal voltage regulator, sleep modes
  * **Software:** Disabling peripherals, clock prescaling
  * **Electronics:** Leakage current, battery life calculation
* [ ] **Watchdog Timer:** The hardware "reset button" when software crashes
* [ ] **EEPROM:** Non-volatile memory endurance and wear leveling
* [ ] **Fuses:** Permanent chip configuration (BE CAREFUL!)


## ⚡ Hardware Setup & Measurement Techniques

### Recommended Test Equipment
```
Essential:                    Better:
├── Multimeter                ├── Digital Oscilloscope
├── Breadboard                ├── Logic Analyzer
├── Jumper Wires              ├── Adjustable Power Supply
├── 220Ω-1kΩ Resistors        ├── Signal Generator
└── LEDs (various colors)     └── Current Probe
```

### Your First Measurement Lab
```c
// Write this code, then MEASURE it:
DDRB |= (1 << PB0);    // Set PB0 as output
PORTB |= (1 << PB0);    // Set PB0 HIGH

// With multimeter: Measure voltage between PB0 and GND
// Expected: ~5V (or VCC)

// Add a 330Ω resistor + LED in series
// With multimeter: Measure voltage across LED (~2V) and resistor (~3V)
// Calculate current: I = V/R = 3V/330Ω = 9mA
```


## 📂 Enhanced Repository Structure

| Folder | Hardware Focus | Software Focus | Register Focus |
| :--- | :--- | :--- | :--- |
| `/01_Blink_Register` | LED current limiting, Ohm's Law | Bit shifting, infinite loops | `DDRB`, `PORTB` |
| `/02_Button_Polling` | Pull-up resistors, switch bounce | Polling loops, debounce | `PINB` |
| `/03_Interrupts` | Interrupt hardware priority | ISR writing, volatile | `GIMSK`, `PCMSK` |
| `/04_PWM_Fading` | RC filtering, analog averaging | Fast PWM mode | `TCCR0A`, `OCR0A` |
| `/05_ADC_LightMeter` | Voltage dividers, sensor interfacing | ADC prescaling, conversion | `ADMUX`, `ADCSRA` |
| `/06_I2C_Scanner` | Pull-up values, bus capacitance | Protocol timing | `USICR`, `USIDR` |
| `/07_Power_Sleep` | Leakage current measurement | Sleep modes, wake sources | `MCUCR`, `PRR` |
| `/08_Watchdog` | External reset circuit | Watchdog configuration | `WDTCR` |


## ⚡ Core Technical Concepts

### The Masking Rules (With Hardware Context)
```c
// SET A BIT (Turn ON/Output)
// Hardware: Enables output driver, sets flip-flop to HIGH
// Current flows from VCC through pin to load
REGISTER |= (1 << BIT);

// CLEAR A BIT (Turn OFF/Input)
// Hardware: Disables output driver (high-Z) OR sets LOW
// Pin becomes input (high impedance) or output LOW sinking current
REGISTER &= ~(1 << BIT);

// TOGGLE A BIT (Flip state)
// Hardware: Output flips from HIGH→LOW or LOW→HIGH
// Current direction reverses if driving a load
REGISTER ^= (1 << BIT);

// CHECK A BIT (Is it 1?)
// Hardware: Input buffer compares pin voltage to threshold
// Returns TRUE if pin > ~0.7*VCC
if (REGISTER & (1 << BIT)) { ... }
```

### The Pin Configuration Matrix
```
DDRxn | PORTxn |                     Result
------|--------|------------------------------------------------
   0  |    0   | Input, High-Z (Tri-state). Pin floating.
   0  |    1   | Input with Pull-up. Pin weakly pulled HIGH.
   1  |    0   | Output LOW. Pin connected to GND (sinking current).
   1  |    1   | Output HIGH. Pin connected to VCC (sourcing current).
```


## 📚 Essential Reading ([See Docs](Docs/))
* [ATtiny85 Datasheet (Sections marked for beginners)](Docs/Atmel-2586-ATtiny85-Datasheet.pdf.pdf) - Pages 46-58 (I/O Ports)
* "The Art of Electronics" by Horowitz & Hill - Chapters 1-3
* AVR Instruction Set Manual - Understanding the assembly behind C
* "Inside the Machine" by Jon Strokes


## 📝 Learning Log
**Date:** 01/03/2026
**Concept Mastered:** GPIO with hardware context  
**Realization:** Setting a bit in PORTB isn't just "turning on an LED" - it's enabling the output driver and connecting the pin to VCC through a CMOS transistor pair. The LED lights because current flows from VCC, through the pin, through the resistor, through the LED, to GND.  

