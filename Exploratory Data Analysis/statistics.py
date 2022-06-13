deaths_data = {
  2000 : 231,
  2001 : 21357,
  2002 : 11685,
  2003 : 33819,
  2004 : 228802,
  2005 : 88003,
  2006 : 6605,
  2007 : 712,
  2008 : 88011,
  2009 : 1790,
  2010 : 320120,
  2011 : 21953,
  2012 : 768
}

deaths = list(deaths_data.values())


# MEAN
s = 0
for d in deaths:
    s = s + d

n = len(deaths)
mean = s / n

print("\nMean is: " + str(mean))


# MEDIAN
deaths.sort()
if n % 2 == 0:
    median1 = deaths[n//2]
    median2 = deaths[n//2 - 1]
    median = (median1 + median2)/2
else:
    median = deaths[n//2]
print("Median is: " + str(median))


# MODE
print("Mode is: " + str(deaths[-1]))


# STANDARD DEVIATION
var = sum((x - mean)**2 for x in deaths) / n
std_dev = var ** 0.5
print("Standard Deviation is: " + str(std_dev))


# COEFFICIENT OF VARIATION
variation = std_dev/mean
print("coefficient of variation: " + str(variation))