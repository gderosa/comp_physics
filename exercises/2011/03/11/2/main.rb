require 'interpolation'

include Math

SUBINTERVALS = 100

@degree = 2

@points = Array.new

def g(x)
  6*x + 2*((cos(x))**2) - 4*(x**2)*sin(x) - (5.0/(x**2))
end

[1.0, 1.5, 2.0, 2.5, 3.0, 3.5, 4.0, 4.5, 5.0].each do |x|
  @points << [x, g(x)]
end

@interpolation = Interpolation::Polynomial.new @points, @degree

@interpolation.each_interpolator do |intpl|
  0.upto(SUBINTERVALS - 1) do |k|
    x = intpl.x.first + k*(intpl.x.last - intpl.x.first)/SUBINTERVALS 
    delta = (g(x) - intpl.interpolate(x)).abs
    puts "#{x} \t #{intpl.interpolate(x)} \t #{delta}"
  end
end

