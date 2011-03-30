#!/usr/bin/env ruby

$LOAD_PATH.unshift(
  "#{File.dirname(__FILE__)}/lib"
)

require 'zero/secant'

include Math

f = lambda {|x| cos(exp(x)) + sin(2*x) - 0.035}

zs = Zero::Secant.new(
  :lower    => -8.0,
  :upper    => 2.0,
  :function => f
)

zs.each do |low, up, pivt, val|
  puts "In [#{low}..#{up}], f(#{pivt}) = #{val}"
end

