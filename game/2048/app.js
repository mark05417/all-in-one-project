const width = 4

var gridDisplay
var scoreDisplay
var bestScoreDisplay
var resultDisplay
var squares = []

var changeStatus = false
var score = 0
var best = 0

var leftEvent = new KeyboardEvent("keyup", {keyCode: 37});
var upEvent = new KeyboardEvent("keyup", {keyCode: 38});
var rightEvent = new KeyboardEvent("keyup", {keyCode: 39});
var downEvent = new KeyboardEvent("keyup", {keyCode: 40});

//create the playing board
function createBoard() {
  for (let i=0; i < width*width; i++) {
    let square = document.createElement('div')
    square.innerHTML = 0
    gridDisplay.appendChild(square)
    squares.push(square)
  }
  generate() // init cell 1
  generate() // init cell 2
}

//generate a new number to an empty cell
function generate() {
  do {
    randomNumber = Math.floor(Math.random() * squares.length)
  } while (squares[randomNumber].innerHTML != 0)
  
  squares[randomNumber].innerHTML = 2
  updateColor()
  checkForWin()
}

//update color
function updateColor() {
  for (let i=0; i < squares.length; i++) {
    if (squares[i].innerHTML == 0) squares[i].style.backgroundColor = '#afa192'
    else if (squares[i].innerHTML == 2) squares[i].style.backgroundColor = '#eee4da'
    else if (squares[i].innerHTML  == 4) squares[i].style.backgroundColor = '#ede0c8' 
    else if (squares[i].innerHTML  == 8) squares[i].style.backgroundColor = '#f2b179' 
    else if (squares[i].innerHTML  == 16) squares[i].style.backgroundColor = '#ffcea4' 
    else if (squares[i].innerHTML  == 32) squares[i].style.backgroundColor = '#e8c064' 
    else if (squares[i].innerHTML == 64) squares[i].style.backgroundColor = '#ffab6e' 
    else if (squares[i].innerHTML == 128) squares[i].style.backgroundColor = '#fd9982' 
    else if (squares[i].innerHTML == 256) squares[i].style.backgroundColor = '#ead79c' 
    else if (squares[i].innerHTML == 512) squares[i].style.backgroundColor = '#76daff' 
    else if (squares[i].innerHTML == 1024) squares[i].style.backgroundColor = '#beeaa5' 
    else if (squares[i].innerHTML == 2048) squares[i].style.backgroundColor = '#d7d4f0' 
  }
}

//control the move
function moveRight() {
  for (let it = 0; it < 4; it ++) {
    for (let i = 0; i < squares.length; i++) {
      if (i % 4 == 3) continue;
      if (squares[i+1].innerHTML == 0){
        [squares[i].innerHTML, squares[i+1].innerHTML] = [squares[i+1].innerHTML, squares[i].innerHTML]
        changeStatus = true
      }
    }
  }
}

function moveLeft() {
  for (let it = 0; it < 4; it ++) {
    for (let i = 0; i < squares.length; i++) {
      if (i % 4 == 3) continue;
      if (squares[i].innerHTML == 0){
        [squares[i].innerHTML, squares[i+1].innerHTML] = [squares[i+1].innerHTML, squares[i].innerHTML]
        changeStatus = true
      }
    }
  }
}

function moveUp() {
  for (let it = 0; it < 4; it ++) {
    for (let i = 0; i < squares.length; i++) {
      if (i >= 12) continue;
      if (squares[i].innerHTML == 0){
        [squares[i].innerHTML, squares[i+4].innerHTML] = [squares[i+4].innerHTML, squares[i].innerHTML]
        changeStatus = true
      }
    }
  }
}

function moveDown() {
  for (let it = 0; it < 4; it ++) {
    for (let i = 0; i < squares.length; i++) {
      if (i >= 12) continue;
      if (squares[i+4].innerHTML == 0){
        [squares[i].innerHTML, squares[i+4].innerHTML] = [squares[i+4].innerHTML, squares[i].innerHTML]
        changeStatus = true
      }
    }
  }
}

function combineLeft() {
  for (let i = 0; i < squares.length; i++) {
    if (i % 4 == 3) continue;
    if (squares[i].innerHTML === squares[i+1].innerHTML) {
      let sum = parseInt(squares[i].innerHTML) + parseInt(squares[i+1].innerHTML);
      [squares[i].innerHTML, squares[i+1].innerHTML] = [sum, 0]
      score += sum
      best = Math.max(best, score)
      scoreDisplay.innerHTML = score
      bestScoreDisplay.innerHTML = best
      changeStatus = true
    }
  }
}

function combineRight() {
  for (let i = squares.length - 1; i >= 0; i--) {
    if (i % 4 == 3) continue;
    if (squares[i].innerHTML === squares[i+1].innerHTML) {
      let sum = parseInt(squares[i].innerHTML) + parseInt(squares[i+1].innerHTML);
      [squares[i].innerHTML, squares[i+1].innerHTML] = [0, sum]
      score += sum
      best = Math.max(best, score)
      scoreDisplay.innerHTML = score
      bestScoreDisplay.innerHTML = best
      changeStatus = true
    }
  }
}

function combineUp() {
  for (let i = 0; i < squares.length; i++) {
    if (i >= 12) continue;
    if (squares[i].innerHTML === squares[i+width].innerHTML) {
      let sum = parseInt(squares[i].innerHTML) + parseInt(squares[i+width].innerHTML);
      [squares[i].innerHTML, squares[i+width].innerHTML] = [sum, 0]
      score += sum
      best = Math.max(best, score)
      scoreDisplay.innerHTML = score
      bestScoreDisplay.innerHTML = best
      changeStatus = true
    }
  }
}

function combineDown() {
  for (let i = squares.length - 1; i >= 0; i--) {
    if (i >= 12) continue;
    if (squares[i].innerHTML === squares[i+width].innerHTML) {
      let sum = parseInt(squares[i].innerHTML) + parseInt(squares[i+width].innerHTML);
      [squares[i].innerHTML, squares[i+width].innerHTML] = [0, sum]
      score += sum
      best = Math.max(best, score)
      scoreDisplay.innerHTML = score
      bestScoreDisplay.innerHTML = best
      changeStatus = true
    }
  }
}

//assign functions to keyCodes
function control(e) {
  changeStatus = false
  if(e.keyCode === 37) { // left
    moveLeft()
    combineLeft()
    moveLeft()
  } else if (e.keyCode === 38) { // up
    moveUp()
    combineUp()
    moveUp()
  } else if (e.keyCode === 39) { // right
    moveRight()
    combineRight()
    moveRight()
  } else if (e.keyCode === 40) { // down
    moveDown()
    combineDown()
    moveDown()
  }

  if (changeStatus){
    generate()
  } 
}

//check for the number 2048 in the squares to win
function checkForWin() {
  for (let i=0; i < squares.length; i++) {
    if (squares[i].innerHTML == 2048) {
      resultDisplay.innerHTML = 'You WIN'
      // document.removeEventListener('keyup', control)
    }
  }
}

//trigger autoplay
function autoplay(sec = 5) {
  function getRandomInt(max) {
    return Math.floor(Math.random() * max);
  }

  function oneMove() {
    let rnd = getRandomInt(1000)
    if(rnd % 4 == 0)      document.dispatchEvent(leftEvent);
    else if(rnd % 4 == 1) document.dispatchEvent(upEvent);
    else if(rnd % 4 == 2) document.dispatchEvent(rightEvent);
    else if(rnd % 4 == 3) document.dispatchEvent(downEvent);
  }

  let player = setInterval(oneMove, 100)
  setTimeout(()=>clearInterval(player), 1000*sec)
}

//trigger reset game
function resetGame() {
  squares = []
  gridDisplay.innerHTML = ''

  score = 0
  scoreDisplay.innerHTML = score
  
  createBoard()
}

// ====== Main Logic ======

document.addEventListener('DOMContentLoaded', () =>  {
  gridDisplay = document.querySelector('.grid')
  scoreDisplay = document.getElementById('score')
  bestScoreDisplay = document.getElementById('best')
  resultDisplay = document.getElementById('result')

  createBoard()

  document.addEventListener('keyup', control)
})