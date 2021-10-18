let xOfCell = [48.9, 49.4, 49.5, 49.5, 49.5];
let loaded = [21.3, 19.6, 19.7, 19.5, 19.2];
let epsilonS = 1.01916;
let voltageAB = 1.995;

let epsilonX = [];
let voltageT = [];
let resistance = [];

let s = 50;

for (let i = 0; i < 5; i++) {
    let eX = epsilonS * (xOfCell[i] / s);
    epsilonX.push(eX);
    let vT = epsilonS * (loaded[i] / s);
    voltageT.push(vT);
    let I = vT/20;
    let r = (eX - vT) / I;
    resistance.push(r);
}

function avgAndStdDev (array) {
    const n = array.length;
    const mean = array.reduce((a, b) => a + b) / n;
    console.log("mean: " + mean);
    const stddev = Math.sqrt(array.map(x => Math.pow(x - mean, 2)).reduce((a, b) => a + b) / n);
    console.log("stddev: " + stddev);
  }
console.log("x Of Cell:");
console.log(avgAndStdDev(xOfCell));

console.log("Loaded cell:");
console.log(avgAndStdDev(loaded));

console.log("EpsilonX:");
console.log(epsilonX);
console.log(avgAndStdDev(epsilonX));

console.log("voltageT:");
console.log(voltageT);
console.log(avgAndStdDev(voltageT));

console.log("resistance:");
console.log(resistance);
console.log(avgAndStdDev(resistance));

const newCellX = [69.0, 70.5, 72.6, 71.4, 71.3];
const oldCellX = [74.1, 74.5, 73.2, 72.7, 76.8];
const daniellCellX = [48.9, 49.4, 49.5, 49.5, 49.5];

console.log("New:");
console.log(newCellX.map(x => x * (voltageAB / 100)));
console.log("Old:");
console.log(oldCellX.map(x => x * (voltageAB / 100)));
console.log("Daniell:");
console.log(daniellCellX.map(x => x * (voltageAB / 100)));