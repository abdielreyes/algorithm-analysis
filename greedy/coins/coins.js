let money = [1,,5,10,20,50,100]
let residualMoney = 99

let selectedMoney = []
let index = money.length - 1

while(residualMoney>0){
	let pay = residualMoney - money[index]

	if(pay>=0){
		selectedMoney.push(money[index])
		residualMoney = pay;
	}else{
		index--;
	}

}
console.log(selectedMoney)
