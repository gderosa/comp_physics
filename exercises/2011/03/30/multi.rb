#!/usr/bin/env ruby

$LOAD_PATH.unshift(
  "#{File.dirname(__FILE__)}/lib"
)

require 'zero/secant'
require 'core/range'

include Math

@f        = lambda {|x| cos(exp(x)) + sin(2*x) - 0.035}
@interval = (-8.0..2.0)

@interval.randomly_partition(32) do |subinterval|
  zs = Zero::Secant.new(
    :lower => subinterval.first,
    :upper => subinterval.last,
    :f     => @f
  )
  x0 = zs.find and puts "#{x0} #{zs.value}" 
end


