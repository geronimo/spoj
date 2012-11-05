def optimal_multiplication chain
  n = chain.size
  (2..n).each do |l|
    (0..n - l).each do |i|
      j = i + l - 1
      @costs[i][j] = 1 << 32
      (i...j).each do |k|
        tmp = @costs[i][k] + @costs[k+1][j] + (color(i, k, chain) * color(k+1, j, chain))
        if tmp < @costs[i][j]
          @costs[i][j] = tmp
        end
      end
    end
  end
  return @costs[0][chain.size - 1]
end

def color i, j, chain
  return @colors[i][j] if @colors[i][j]
  result = 0
  (i..j).each do |k|
    result += chain[k]
  end
  return result % 100
end

while mixtures_count = gets do
  mixtures = gets
  mixtures = mixtures.split(" ").map { |m| m.to_i }

  n = mixtures.size
  @costs = Array.new(n) { Array.new(n) { 0 } }
  @colors = Array.new(n) { Array.new(n) { nil } }

  puts optimal_multiplication(mixtures)
end
