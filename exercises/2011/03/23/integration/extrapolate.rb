#!/usr/bin/env ruby

require 'fileutils'

DIR = File.dirname(__FILE__)

$LOAD_PATH.unshift(
  File.join(DIR, '../../../../../ruby/lib') 
)

require 'interpolator'

BINDIR              = "#{DIR}/bin"
OUTDIR              = "#{DIR}/output"
INTEGRALS_FILE      = "#{OUTDIR}/integrals.dat"
EXTRAPOLATION_FILE  = "#{OUTDIR}/extrapolation.dat"

FileUtils.mkdir_p OUTDIR

system("#{BINDIR}/integration > #{INTEGRALS_FILE}")

points = Array.new

File.foreach INTEGRALS_FILE do |line|
  points << line.split.map{|capture| capture.to_f} 
end

interpolator = Interpolator::Polynomial.new(points)

x   = 0.0
dx  = 0.001

File.open EXTRAPOLATION_FILE, 'w' do |f|
  while(x <= 0.5) 
    f.puts "#{x}\t#{interpolator.interpolate(x, :extrapolate)}" 
    x += dx
  end
end

puts interpolator.interpolate(0.0, :extrapolate)


