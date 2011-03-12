# Excercise #1, 2011-03-11
# Computational Pysics, University of Naples "Federico II"

# Linear interpolation

include Math

DATFILE       = 'data.dat'
SUBINTERVALS  = 100

@x          = Array.new
@y          = Array.new
@max_delta  = 0

# Read data from DATFILE and put them into @x and @y Arrays
File.foreach DATFILE do |line|
  if line =~ /(\S+)\s+(\S+)/
    @x << $1.to_f
    @y << $2.to_f
  end
end

def f(x) 
  cos(log x) + x + 2
end

for i in 0..(@x.length - 2) do
  subinterval = (@x[i+1] - @x[i]) / SUBINTERVALS
  for j in 0..(SUBINTERVALS - 1)
    x = @x[i] + j * subinterval
    interpolate = @y[i] + ((@y[i+1] - @y[i])/(@x[i+1] - @x[i])) * (x - @x[i])
    delta = (f(x) - interpolate).abs
    @max_delta = delta if delta > @max_delta
    puts "x = #{x} \t Delta = #{delta} "
  end
end

puts "Maximun Delta = #{@max_delta}"




