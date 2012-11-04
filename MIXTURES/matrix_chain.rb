class Matrix
  attr_accessor :columns, :rows

  def initialize(rows, columns)
    self.columns = columns
    self.rows = rows
  end
end

class Multiplicator
  attr_accessor :chain, :costs, :p

  def initialize(chain)
    self.chain = chain

    self.costs = []
    (0...chain.size).each do |i|
      self.costs[i] = []
      self.costs[i][i] = 0
    end

    self.p = []
    (0...chain.size).each do |i|
      self.p[i] = self.chain[i].rows
    end
    self.p[chain.size] = chain[chain.size - 1].columns
  end

  def optimal_multiplication
    n = p.size - 1
    (2..n).each do |l|
      (0..n - l).each do |i|
        j = i + l - 1
        self.costs[i][j] = 1 << 32
        (i...j).each do |k|
          tmp = self.costs[i][k] + self.costs[k+1][j] + (self.p[i] * self.p[k+1] * self.p[j+1])
          if tmp < self.costs[i][j]
            self.costs[i][j] = tmp
          end
        end
      end
    end
    return self.costs[0][chain.size - 1]
  end
end

test_case = [Matrix.new(30, 35), Matrix.new(35, 15), Matrix.new(15, 5), Matrix.new(5, 10), Matrix.new(10, 20), Matrix.new(20, 25)]
m = Multiplicator.new(test_case)
ap m.optimal_multiplication
ap m.costs
