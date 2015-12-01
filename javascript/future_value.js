var $ = function (id){
  return document.getElementById(id);
}

var calculate_click = function(){
  var investment = parseFloat( $("investment").value);
  var annualRate = parseFloat( $("rate").value);
  var years = parseInt( $("years").value);
  $("futureValue").value = "";
  if (isNaN(investment) || investment <= 0){
    alert("Investment must be a valid number \n and greater than zero.");
  }
  else if (isNaN(annualRate) || annualRate <= 0){
    alert("Annual rate must be a valid number \n and greater than zero.");
  }
  else if (isNaN(years) || years <= 0){
    alert("Years must be a valid number \n and greater than zero.");
  }
  else{
    var monthlyRate = annualRate / 12 / 100;
    var months = years * 12;
    var futureValue = 0;
    for (i = 1; i <= months; i++){
      futureValue = (futureValue + investment) * (1 + monthlyRate);
    }
    $("futureValue").value = futureValue.toFixed(2);
  }
  }
var clear_click = function(){
  $("investment").value = "";
  $("rate").value = "";
  $("years").value = "";
  $("futureValue").value = "";
}
  window.onload = function(){
    $("calculate").onclick = calculate_click;
    $("clearClick").onclick = clear_click;
    $("investment").focus();
}
