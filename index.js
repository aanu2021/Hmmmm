const express = require("express");
const app = express();

app.get('/',async(req,res)=>{

    let response = await fetch(`https://jsonmock.hackerrank.com/api/transactions`);
    let data = await response.json();
    let total_pages = data.total_pages;
    let curr_pages = 1;
    let maxCredit = 0.0, maxDebit = 0.0;

    while(curr_pages <= total_pages){
        response = await fetch(`https://jsonmock.hackerrank.com/api/transactions?page=${curr_pages}`);
        data = await response.json();
        const arr = data.data;
        const filterArr = arr.filter((ele)=>{
            return (ele.userName==="Bob Martin" && ele.location.city==="Bourg");
        });
        filterArr.map((ele)=>{
            if(ele.txnType === "debit"){
                 let strAmount = ele.amount;
                 let actualAmount = strAmount.substr(1);
                 actualAmount = actualAmount.replaceAll(",","");
                 let amt = parseFloat(actualAmount);
                 maxDebit = Math.max(maxDebit, amt);
            }
            else{
                let strAmount = ele.amount;
                let actualAmount = strAmount.substr(1);
                actualAmount = actualAmount.replaceAll(",","");
                let amt = parseFloat(actualAmount);
                maxCredit = Math.max(maxCredit, amt);
            }
        })
        curr_pages++;
    }
    console.log(maxCredit);
    console.log(maxDebit);
    // let credit = maxCredit.toString();
    // let debit = maxDebit.toString();
    // credit = "$" + credit;
    // debit = "$" + debit;
    // console.log(credit);
    // console.log(debit);
    let s1 = new Intl.NumberFormat().format(maxCredit); 
    let s2 = new Intl.NumberFormat().format(maxDebit);
    s1 = "$" + s1;
    s2 = "$" + s2;
    console.log(s1);
    console.log(s2);
    res.send("<h1>Hello World I am back</h1>");
})
app.listen(3000,()=>{
    console.log("Server is listening at port no 3000");
})