const express = require("express");
const app = express();


/* City Weather Station */

// const sortedFunction = (a,b)=> {
//     return a[0].localeCompare(b[0]);
// }

// app.get('/',async(req,res)=>{

//     let keyword = "all";

//     let response = await fetch(`https://jsonmock.hackerrank.com/api/weather/search?name=${keyword}`);
//     let data = await response.json();
//     let total_pages = data.total_pages;
//     let num_pages = 1;

//     let container = [];

//     while(num_pages <= total_pages){
//          response = await fetch(`https://jsonmock.hackerrank.com/api/weather/search?name=${keyword}&page=${num_pages}`);
//          data = await response.json();
//          let arr = data.data;
//          arr.map((ele)=>{
//             let current = [];
//             current.push(ele.name);
//             current.push(ele.weather.substr(0,ele.weather.search(" degree")));
//             let wind = ele.status[0];
//             wind = wind.substr(6);
//             let idx = wind.search("Kmph");
//             wind = wind.substring(0,idx);
//             current.push(wind);
//             let humidity = ele.status[1];
//             humidity = humidity.substr(10);
//             idx = humidity.search("%");
//             humidity = humidity.substring(0,idx);
//             current.push(humidity);
//             container.push(current);
//          })
//          num_pages++;
//     }

//     container.sort(sortedFunction);

//     console.log(container);

//     res.send("<h1>Hello World</h1>");

// })




/* Asteroid Orbits */

// const sortFunc = (a,b)=> {
//     let a1 = parseFloat(a[1]);
//     let b1 = parseFloat(b[1]);
//     if(a1 === b1){
//         let idx = a[0].search(" ");
//         let a2 = a[0].substr(idx+1);
//         a2 = a2.substring(0,a2.length-1);
//         idx = b[0].search(" ");
//         let b2 = b[0].substr(idx+1);
//         b2 = b2.substring(0,b2.length-1);
//         return a2.localeCompare(b2);
//     }
//     return a1-b1;
// }

// app.get('/',async(req,res)=>{
//     let response = await fetch(`https://jsonmock.hackerrank.com/api/asteroids/search`);
//     let data = await response.json();
//     let total_pages = data.total_pages;
//     let curr_pages = 1;
//     let container = [];
//     let orbitClass = "aten";
//     let year = 2010;
//     while(curr_pages <= total_pages){
//         response = await fetch(`https://jsonmock.hackerrank.com/api/asteroids/search?page=${curr_pages}`);
//         data = await response.json();
//         let arr = data.data;
//         let newArr = arr.filter((ele)=>{
//             return ele.orbit_class.toLowerCase().includes(orbitClass.toLowerCase()) && ele.discovery_date.substr(0,4)==year;
//         });
//         newArr.map((ele)=>{
//             container.push([ele.designation,ele.period_yr ? ele.period_yr : "1"]);
//         });
//         curr_pages++;
//     }
//     container.sort(sortFunc);
//     let answer = [];
//     container.map((ele)=>{
//         answer.push(ele[0]);
//     })
//     console.log(answer);
//     res.send("<h1>Hello World</h1>");
// })




/* Countries with regions */

// function customFunc(a,b){
//     if(a[1] === b[1]){
//         return a[0].localeCompare(b[0]);
//     }
//     return a[1] - b[1];
// }

// app.get('/',async(req,res)=>{
//    let keyword = "an";
//    let region = "Asia"; 
//    let response = await fetch(`https://jsonmock.hackerrank.com/api/countries/search?region=${region}&name=${keyword}`);
//    let data = await response.json();
//    let total_pages = data.total_pages;
//    let curr_pages = 1;
//    let container = [];
//    while(curr_pages <= total_pages){
//       response = await fetch(`https://jsonmock.hackerrank.com/api/countries/search?region=${region}&name=${keyword}&page=${curr_pages}`);
//       data = await response.json();
//       const arr = data.data;
//       arr.map((ele)=>{
//         container.push([ele.name,ele.population]);
//       })
//       curr_pages++;
//    }
//    container.sort(customFunc);
//    container.map((ele)=>{
//     console.log(ele[0] + ", " + ele[1]);
//    });
//    res.send("<h1>Hello World</h1>");
// })




/* Credit and Debit Maximum */

// app.get('/',async(req,res)=>{

//     let response = await fetch(`https://jsonmock.hackerrank.com/api/transactions`);
//     let data = await response.json();
//     let total_pages = data.total_pages;
//     let curr_pages = 1;
//     let maxCredit = 0.0, maxDebit = 0.0;

//     while(curr_pages <= total_pages){
//         response = await fetch(`https://jsonmock.hackerrank.com/api/transactions?page=${curr_pages}`);
//         data = await response.json();
//         const arr = data.data;
//         const filterArr = arr.filter((ele)=>{
//             return (ele.userName==="Bob Martin" && ele.location.city==="Bourg");
//         });
//         filterArr.map((ele)=>{
//             if(ele.txnType === "debit"){
//                  let strAmount = ele.amount;
//                  let actualAmount = strAmount.substr(1);
//                  actualAmount = actualAmount.replaceAll(",","");
//                  let amt = parseFloat(actualAmount);
//                  maxDebit = Math.max(maxDebit, amt);
//             }
//             else{
//                 let strAmount = ele.amount;
//                 let actualAmount = strAmount.substr(1);
//                 actualAmount = actualAmount.replaceAll(",","");
//                 let amt = parseFloat(actualAmount);
//                 maxCredit = Math.max(maxCredit, amt);
//             }
//         })
//         curr_pages++;
//     }
//     console.log(maxCredit);
//     console.log(maxDebit);
//     let s1 = new Intl.NumberFormat().format(maxCredit); 
//     let s2 = new Intl.NumberFormat().format(maxDebit);
//     s1 = "$" + s1;
//     s2 = "$" + s2;
//     console.log(s1);
//     console.log(s2);
//     res.send("<h1>Hello World I am back</h1>");
// })




app.listen(3000,()=>{
    console.log("Server is listening at port no 3000");
})


/* Website Link  :   https://thejoboverflow.com/p/p1439/   */
