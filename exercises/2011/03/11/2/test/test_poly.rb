require 'test/unit'

require 'interpolator'

class TestPolynomialInterpolation < Test::Unit::TestCase
  EPSREL = 1e-8

  def test_xsquare
    # y = x^2
    intp = Interpolator::Polynomial.new(
      [100.0, 1.0e4 ], 
      [ -4.0,  16.0 ],
      [ -1.0,  1.0  ],
      [  3.0,  9.0  ]         
    )

    [12.0, -3.567e7, 5.345345e-4].each do |x|

      y_expected  = x**2

      assert_in_delta(
        y_expected,
        intp.interpolate(x, :extrapolate),
        y_expected * EPSREL
      )

    end

  end

end



