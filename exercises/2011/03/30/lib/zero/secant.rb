module Zero
  class Secant
    attr_reader :lower, :upper, :pivot, :steps, :maxsteps, :epsilon
    def initialize(h, &f)
      @steps    = 0
      @maxsteps = h[:maxsteps] || 1<<32
      @lower    = h[:lower]
      @upper    = h[:upper]
      @epsilon  = h[:epsilon] || 1e-12
      @pivot    = (@lower + @upper)/2.0 
      @f        = f || h[:f] || h[:function] 
    end
    def lambda
      @f
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
      while 
          f(@upper) * f(@lower) < 0           and 
          value.abs > @epsilon                and
          @steps < @maxsteps
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


