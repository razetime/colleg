nfa = {
    :q0 => {0 => [:q0], 1 => [:q1], e => []},
    :q1 => {0 => [:q1,:q2], 1 => [:q1], e => []},
    :q2 => {0 => [:q2], 1 => [:q1,:q2], e => []},
}

final_states = [:q2]

dfa = {}
curr = [[:q0]]
existing = nfa.keys.map{[_1]}

while curr.size > 0  do
    n_st = curr.pop      
    n_hsh = Hash.new []
    for i in n_st do
        for k,v in nfa[i] do
            n_hsh[k] = n_hsh[k].union v
        end
    end
    dfa[n_st] = n_hsh
    existing = existing.union n_hsh.values
end

p 

