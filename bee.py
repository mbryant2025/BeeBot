import enchant
import itertools

d = enchant.Dict("en_US")

key_letter = 'e'

other_letters = key_letter + 'tanopr'
other_letters = other_letters.lower()

for i in range(4, 10):
    for combo in itertools.product(other_letters, repeat=i):
        word = ''.join(combo)
        if key_letter not in word:
            continue
        if d.check(word):
            print(word)

