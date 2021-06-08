// Adapted from Learning Processing
// Daniel Shiffman
// http://www.learningprocessing.com

// Example: Oscillator Frequency

let i = 0;
let playerY = 300;
let playerX = 300;

let desiredY = 600;

var osc;

function setup() {
  createCanvas(windowWidth,windowHeight);
  playerY = windowHeight / 2;

  // Instantiate a Sine Wave Oscillator
  osc = new p5.SinOsc();

  // Tell the Oscillator to start oscillating.
  // We hear the frequency of these oscillators as a pitch.
  osc.start();

  // Oscillator has an output amplitude of 0.5 by default.
  // We can make it louder.
  osc.amp(1);
}

class movePlayer{
  playerY =+ 0.01*(playerY - desiredY);
}

function draw() {
  background(200);

  // map the mouseX to set frequency of the between 40 and 880 Hz
  var freq = map(playerY, 0, windowHeight, 880, 40);
  osc.freq(freq);
  ellipse(300 + 30*sin(i++/100), playerY, 32, 32);

  movePlayer();
}
