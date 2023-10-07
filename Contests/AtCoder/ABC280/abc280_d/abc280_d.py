import math


def main():
	K = int(input())

	prime_factors = []
	dup = K

	for factor in range(2, int(math.sqrt(K)) + 1):
		if dup % factor == 0:
			cnt = 0
			while dup % factor == 0:
				cnt += 1
				dup = dup // factor

			prime_factors.append([factor ,cnt])
	if dup > 1:
		prime_factors.append([dup, 1])
	# print(prime_factors)

	l, r = 0, K

	# print(l, r)

	while r > l + 1:
		m = (l + r) // 2
		# print(m)
		good = True

		for factor, times in prime_factors:
			cnt = 0
			p = factor
			while p <= m:
				cnt += (m // p)
				p = p * factor
			# print("factor = {}, times = {}, cnt = {}, m = {}".format(factor, times, cnt, m))

			if cnt < times:
				good = False
				break
		# print("r = {}, l = {}".format(r, l))
		if good:
			r = m
		else:
			l = m
		# print()
	print(r)

if __name__ == '__main__':
	main()