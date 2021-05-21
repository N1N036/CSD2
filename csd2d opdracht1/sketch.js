// Adapted from Learning Processing
// Daniel Shiffman
// http://www.learningprocessing.com

// Example: Oscillator Frequency

let t = 0;
let playerY = 0;
let playerX = 1000;

let desiredY;
let stepsize;

var osc;
var consonance



let border = 100;

class Enemy{
  constructor(){
    this.x = windowWidth/2;
    this.y = stepsize*int(random(0,12));
    this.desiredY = stepsize*int(random(3,9));
  }
  createEnemy(){
    this.y += 0.07*(this.desiredY - this.y);
    ellipse(this.x,this.y,1000*consonance,20);
    stroke(255,255);
  };
  moveEnemy(){
    if (t % (20*int(random(5,40))) == 0){
      this.desiredY = stepsize * (Math.floor(random(3,9)));
    }
  };
}


class Particle {
// setting the co-ordinates, radius and the
// speed of a particle in both the co-ordinates axes.
  constructor(){
    this.x = random(0,width);
    this.y = random(0,height);
    this.r = random(1,8);
    this.xSpeed = random(-2,2);
    this.ySpeed = random(-1,1.5);
  }

// creation of a particle.
  createParticle() {
    noStroke();
    fill('rgba(200,169,169,0.5)');
    circle(this.x,this.y,this.r);
  }

// setting the particle in motion.
  moveParticle() {
    if(this.x < 0 || this.x > width)
      this.xSpeed*=-1;
    if(this.y < 0 || this.y > height)
      this.ySpeed*=-1;
    this.x+=this.xSpeed;
    this.y+=this.ySpeed;
  }

// this function creates the connections(lines)
// between particles which are less than a certain distance apart
  joinParticles(particles) {
    particles.forEach(element =>{
      let dis = dist(this.x,this.y,element.x,element.y);
      if(dis<85) {
        stroke('rgba(255,255,255,0.04)');
        line(this.x,this.y,element.x,element.y);
      }
    });
  }
}

let particles = [];
let planes = [];


function Consonance(f1,f2){
  var fmin = Math.min(f1,f2);
  var fmax = Math.max(f1,f2);
  var s = 0.24 / (0.021 * fmax + 19.0);
  return exp(-3.5 * s * (fmax - fmin)) - exp(-5.75 * s * (fmax - fmin));
}


function setup() {
  createCanvas(windowWidth-border/2,windowHeight-border/2);
  stepsize = int((windowHeight - (2 * border))/12);
  desiredY = stepsize*int(random(0,12));
  playerY = stepsize*int(random(0,12));

  system = new ParticleSystem(createVector(playerX, playerY));

  for(let i = 0;i<width/10;i++){
    particles.push(new Particle());
  }

  for(let k = 0;k< 3;k++){
   planes.push(new Enemy(i = k));
  }

  // Instantiate a Sine Wave Oscillator
  osc = new p5.TriOsc();
  osc1 = new p5.TriOsc();
  osc2 = new p5.TriOsc();

  // Tell the Oscillator to start oscillating.
  // We hear the frequency of these oscillators as a pitch.
  osc.start();
  osc1.start();
  osc2.start();

  // Oscillator has an output amplitude of 0.5 by default.
  // We can make it louder.
  osc.amp(0.07);
  osc1.amp(0.07);
  osc2.amp(0.07);
}

function keyPressed(){
  if (keyCode === UP_ARROW){
       if (abs(desiredY - playerY) < windowHeight/6){
          i -= 1;
         desiredY = 0.5*stepsize*int(i);
       }
    }
  if (keyCode === DOWN_ARROW){
    if (abs(desiredY - playerY) < windowHeight/6){
      i += int(1);
      desiredY = 0.5*stepsize*int(i);
    }
  }
}

function draw() {
  t += 1;
  background(200);
  smoke.addParticle();
  smoke.run();
  stroke(255,255);
  // map the mouseX to set frequency of the between 40 and 880 Hz
  var freq = map(planes[0].y, border, windowHeight - border, 110	, 55) ** 2 / 32;
  var freq1 = map(planes[1].y, border, windowHeight - border, 110	, 55) ** 2 / 32;
  var freq2 = map(planes[2].y, border, windowHeight - border, 110	, 55) ** 2 / 32;
  consonance = Consonance(freq, freq1) + Consonance(freq, freq2) +
              Consonance(freq1, freq2) + Consonance(freq1, freq);
              //Consonance(freq2, freq1) + Consonance(freq2, freq);
 planes[0].desiredY = desiredY;
  playerX =planes[0].x;
  playerY =planes[0].y;
  osc.freq(freq);
  osc1.freq(freq1);
  osc2.freq(freq2);

  for(let k = 0;k<3;k++) {
   planes[k].createEnemy();
  }
  for(let k = 1;k<3;k++) {
   planes[k].moveEnemy();
  }
  for(let i = 0;i<particles.length;i++) {
    particles[i].createParticle();
    particles[i].moveParticle();
    particles[i].joinParticles(particles.slice(i));
  }
}


// A simple Particle class
let Particle = function(position) {
  this.acceleration = createVector(0.0, 0.0);
  this.velocity = createVector(random(-10, -5), random(-0.5, 0.5));
  this.position = createVector(playerX, playerY);
  this.lifespan = 70;
};

Particle.prototype.run = function() {
  this.update();
  this.display();
};

// Method to update position
Particle.prototype.update = function(){
  this.velocity.add(this.acceleration);
  this.position.add(this.velocity);
  this.lifespan -= 2;
};

// Method to display
Particle.prototype.display = function() {
  stroke(200, this.lifespan);
  strokeWeight(2);
  fill(127, this.lifespan*3);
  ellipse(this.position.x, this.position.y, 12, 12);
};

// Is the particle still useful?
Particle.prototype.isDead = function(){
  return this.lifespan < 0;
};

let ParticleSystem = function(position) {
  this.origin = createVector(playerX, playerY);
  this.particles = [];
};

ParticleSystem.prototype.addParticle = function() {

  this.particles.push(new Particle(this.origin));

};

ParticleSystem.prototype.run = function() {
  for (let i = this.particles.length-1; i >= 0; i--) {
    let p = this.particles[i];
    p.run();
    if (p.isDead()) {
      this.particles.splice(i, 1);
    }
  }
};
