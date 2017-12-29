# swiss ephemeris simple result
more simple swiss ephemeris test(swetest).

## usage
- download swetest from [Swiss Ephemeris ftp area](ftp://ftp.astro.com/pub/swisseph).
- copy swetest2.c to src directory.
- replace src/Makefile to this package.
- cd to src and make swetest2.
- copy ephemeris file you want to use(semo_18.se1, sepl_18.se1, seas_18.se1) to src directory.

## parameters
/path/to/swetest2 -y2000 -m12 -d31 -h12 -i0 -s0 -a39 -o139 
y: year
m: month
d: day
h: hour
i: minute
s: second
a: latitude
o: longitude
