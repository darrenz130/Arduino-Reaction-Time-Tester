<h1>Arduino Reaction Time Tester PCB Design</h1>

<h2>Overview</h2>

<p>
This project is an Arduino-based reaction time testing system designed to measure human response speed with millisecond accuracy. The system uses LEDs as visual stimuli, a push button for user input, and a display to show reaction time results. The firmware is written in C++ and implemented on a custom PCB designed in KiCad.
</p>

<h2>Project Walkthrough</h2>

<h3>1. Breadboard Prototype</h3>

<p>
The initial version of the circuit was built and tested on a breadboard to validate functionality. This phase focused on verifying LED triggering, button input detection, and reaction timing accuracy.
</p>

<!-- IMAGE: breadboard.jpg -->

<h3>2. Firmware Development</h3>

<p>
The system was programmed in C++ using the Arduino IDE. The code handles randomized LED stimulus timing, button press detection, and calculates reaction time in milliseconds using precise timing functions.
</p>

<!-- OPTIONAL: firmware explanation or snippet image -->

<h3>3. Schematic Design</h3>

<p>
A full circuit schematic was created in KiCad to define the electrical connections between the Arduino, LEDs, button, and display.
</p>

<!-- IMAGE: schematic.png -->

<h3>4. PCB Design</h3>

<p>
A custom PCB shield was designed in KiCad to replace the breadboard setup. This reduced wiring complexity, improved reliability, and created a compact final hardware design.
</p>

<!-- IMAGE: pcb_layout.png + pcb_3d.png -->

<h3>5. Final Testing</h3>

<p>
The assembled PCB was tested to ensure correct timing accuracy, stable input detection, and consistent system performance.
</p>

<!-- IMAGE or VIDEO: final_board.jpg or demo video -->

<h2>Languages and Tools Used</h2>

<ul>
  <li>C++</li>
  <li>Arduino IDE</li>
  <li>KiCad (PCB Design)</li>
  <li>Breadboard Prototyping</li>
  <li>Multimeter / Circuit Debugging</li>
</ul>

<h2>Files in This Repository</h2>

<ul>
  <li><b>/firmware</b> → Arduino C++ code</li>
  <li><b>/pcb</b> → KiCad schematic and PCB files</li>
  <li><b>/images</b> → Project screenshots and renders</li>
  <li><b>/video</b> → Demo of working system</li>
</ul>

<h2>Demo</h2>

<p>
A short demonstration of the system in action:
<br>
(Insert YouTube link or video here)
</p>

<h2>Key Features</h2>

<ul>
  <li>Millisecond-level reaction time measurement</li>
  <li>Randomized LED stimulus timing</li>
  <li>Custom PCB shield for improved reliability</li>
  <li>Fully tested breadboard prototype before final design</li>
</ul>
