/* Sieve of Eratosthenes program in Node.js */
console.log("erat");

var max = parseInt(process.argv[2])
console.log("max: " + max)

var t1 = Date.now()

var sieve = new Array(max)
//console.log(sieve.length)
sieve[0] = sieve[1] = false

for(var i = 2; i < max; i++) {
  sieve[i] = true
}

var lim = Math.trunc(Math.sqrt(max))
//console.log(lim)

for (n = 2; n < lim; n++) {
  if (sieve[n]) {
    for (j = 2 * n; j < max; j += n) {
      sieve[j] = false
    }
  }
}

//console.log(sieve)
var t2 = Date.now()
var tt = t2 - t1
console.log(tt + " ms")
