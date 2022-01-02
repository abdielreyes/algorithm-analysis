let memo = []
//tiene como limite la stack
function memoizedFibo(n,memo){
	console.log("Calculating Fibonacci for "+n)
	if(memo[n] != undefined){
		return memo[n]
	}
	if(n<=1){
		memo[n] = n;
		return n;
	}else{
		let res = memoizedFibo(n-1, memo) + memoizedFibo(n-2,memo)
		memo[n] = res
		return res
	}
}
//tiene como limite el int
function linearFibo(n){
	let memo = [0,1]
	for(let i = 2; i<=n; i++){
		memo[i] = memo[i-2] + memo[i-1]
	}
	return memo[n]
}
console.log(linearFibo(50));
