class Range
  def randomly_partition(n)
    average_step = (last - first)/n
    new_first = first
    new_last  = first + 2 * rand * average_step
    
    while(self.include? new_last) 
      yield (new_first..new_last)
      new_first = new_last
      new_last = new_last + 2 * rand * average_step
    end

    yield new_first..last if new_first < last
  end
end
