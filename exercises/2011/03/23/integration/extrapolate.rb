@dir = File.dirname(__FILE__)

$LOAD_PATH.unshift(
  File.join(@dir, '../../../../../ruby/lib') 
)

require 'interpolator'

@points = Array.new

`#{@dir}/bin/integration`.each_line do |line|
  @points << line.split.map{|capture| capture.to_f} 
end

p @points

interpolator = Interpolator::Polynomial.new(@points)

puts interpolator.interpolate(0.0, :extrapolate)


