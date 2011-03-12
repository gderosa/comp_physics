module Interpolator
  class Polynomial

    # Number of points determines the degree of the interpolation,
    # e.g. 3 points => quadratic interpolation.
    
    attr_reader :x, :y

    def initialize(*points)
      @n = points.length - 1 # polyonomial degree
      raise ArgumentError, "You must provide at least 2 points" unless @n > 0
      @x = Array.new
      @y = Array.new
      points.sort{|a, b| a[0] <=> b[0]}.each do |point| 
        @x << point[0]
        @y << point[1]
      end
    end

    def p_n(x)
      p_n = Array.new(@n) 
      0.upto @n do |j|
        p_n[j] = 1
        0.upto @n do |k|
          next if k == j
          p_n[j] *= (
            (x - @x[k]) / (@x[j] - @x[k])
          )
        end
      end
      return p_n
    end

    def interpolate(x, *opts)   
      p_n = p_n(x)  

      range = @x.first..@x.last
      raise RangeError, "Value #{x} out of range #{range}" unless
          opts.include? :extrapolate or range.include? x
      retval = 0
      0.upto @n do |j|
        retval += @y[j] * p_n[j]  
      end

      return retval
    end

  end
end

