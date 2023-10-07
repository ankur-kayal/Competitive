def main():
	H, W, N, h, w = map(int, input().split())

	A = []
	for i in range(H):
		tmp = list(map(int, input().split()))
		A.append(tmp)

	unique = 0
	cnt = [0 for i in range(N + 1)]
	tmp = [0 for i in range(N + 1)]

	for i in range(H):
		for j in range(W):
			cnt[A[i][j]] += 1
			if cnt[A[i][j]] == 0:
				unique += 1

	for k in range(H - h):
		for l in range(W - w):
			if l == 0:
				for i in range(k, k + h):
					for j in range(l, l + w):
						print(k, l, i, j)
						cnt[A[i][j]] -= 1
						cnt[A[i][j]] += 1
						if cnt[A[i][j]] == 0:
							unique -= 1

			else:
				for i in range(k, k + h):
					cnt[A[i][l]] += 1
					tmp[A[i][l]] += 1

					if cnt[A[i][j]] == 1:
						unique += 1

					cnt[A[i][l + w - 1]] -= 1
					tmp[A[i][l + w - 1]] -= 1
					if cnt[A[i][l + w - 1]] == 0:
						unique -= 1

			print(unique, end=" ")
		print()


if __name__ == '__main__':
	main()