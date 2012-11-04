class Mixture
  attr_accessor :value

  def initialize(value)
    self.value = value
  end
end

class Multiplicator
  attr_accessor :chain, :costs, :colors

  def initialize(chain)
    self.chain = chain

    self.costs = []
    (0...chain.size).each do |i|
      self.costs[i] = []
      self.costs[i][i] = 0
    end
  end

  def optimal_multiplication
    n = chain.size
    (2..n).each do |l|
      (0..n - l).each do |i|
        j = i + l - 1
        self.costs[i][j] = 1 << 32
        (i...j).each do |k|
          tmp = self.costs[i][k] + self.costs[k+1][j] + (color(i, k) * color(k+1, j))
          if tmp < self.costs[i][j]
            self.costs[i][j] = tmp
          end
        end
      end
    end
    return self.costs[0][chain.size - 1]
  end
  
  def color i, j
    result = 0
    (i..j).each do |k|
      result += chain[k].value
    end
    return result % 100
  end
end

while mixtures_count = gets do
  mixtures = gets
  mixtures = mixtures.split(" ")
  chain = []
  for m in mixtures
    chain.push Mixture.new(m.to_i)
  end

  m = Multiplicator.new(chain)
  puts m.optimal_multiplication
end
