module Zero
  class Secant
    attr_reader :lower, :upper, :pivot
    def initialize(h, &f)
      @lower    = h[:lower]
      @upper    = h[:upper]
      @epsilon  = h[:epsilon] || 1e-12
      @pivot  = (@lower + @upper)/2.0 
      @f      = f
    end
    def f(x)
      @f.call(x)
    end
    def value
      f(@pivot)
    end
    def find
      each {}
      return @pivot if value.abs < @epsilon
    end
    def each
      while f(@upper) * f(@lower) < 0 and value.abs > @epsilon
        yield @lower, @upper, @pivot, value()
        @pivot = @lower - f(@lower) * (@upper-@lower) / (f(@upper)-f(@lower)) 
        if f(@pivot)*f(@lower) < 0
          @upper = @pivot
        elsif f(@pivot)*f(@upper) < 0
          @lower = @pivot
        end
      end
      yield @lower, @upper, @pivot, value()
    end
    alias iterate each
  end
end

include Math

f = lambda {|x| cos(exp(x)) + sin(2*x) - 0.035}

zs = Zero::Secant.new(
  :lower  => -8.0,
  :upper  => 2.0,
  &f
) 

zs.each do |low, up, pivt, val|
  puts "In [#{low}..#{up}], f(#{pivt}) = #{val}" 
end



500.times do |i|
  print "# #{i}:\t" 
  two_points = [-8.0 + 10.0*rand, -8.0 + 10.0*rand]
  zero = Zero::Secant.new(
    :lower  => two_points.min,
    :upper  => two_points.max,
    &f
  ).find and print zero
  puts
end
