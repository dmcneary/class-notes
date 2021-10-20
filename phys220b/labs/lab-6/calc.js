let expParallel = 3.72 * Math.pow(10, -6);
let expSeries = 1.35 * Math.pow(10, -6);
let theoParallel = 3.88 * Math.pow(10, -6);
let theoSeries = 8.98 * Math.pow(10, -7);

let diffParallel = 100 * (Math.abs(expParallel - theoParallel) / ((expParallel + theoParallel) / 2));
let diffSeries = 100 * (Math.abs(expSeries - theoSeries) / ((expSeries + theoSeries) / 2));

console.log(`Percent difference parallel: ${diffParallel}`);
console.log(`Percent difference series: ${diffSeries}`);