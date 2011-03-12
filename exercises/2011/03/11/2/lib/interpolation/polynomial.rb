autoload :Interpolator, 'interpolator'

module Interpolation
  class Polynomial

    def initialize(points, degree)
      @degree = degree
      raise ArgumentError, "Degree must be > 0"                 unless 
          @degree        > 0
      raise ArgumentError, "Number of points must be > degree"  unless
          points.length > @degree
      @points = points.sort{|a, b| a[0] <=> b[0]} 
    end

    def each_interpolator
      first_index = 0
      while first_index + @degree < @points.length
        yield Interpolator::Polynomial.new(
          *@points[(first_index)..(first_index + @degree)] 
        )
        first_index += @degree
      end
    end

  end
end

