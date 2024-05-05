<template>
  <div id="app">
  <h1>Tic Tac Toe</h1>
  <div class="info">
    <span class="player">Player: {{ showSymbol(player) }}</span>
    <span class="win">Winner: {{ showSymbol(winner) }}</span>
  </div>

  <button class="btn_reset" @click="reset">Reset &#8635;</button>
  
  <div class="grids">
    <div class="grid"
      v-for="(grid, idx) in grids"
      :key="idx"
      @click="placeSymbol(idx)"
    >
      {{ showSymbol(grid) }}
    </div>
  </div>
    
  </div>
</template>


<script>
const winLineSets = [
  [0, 1, 2], [3, 4, 5], [6, 7, 8],
  [0, 3, 6], [1, 4, 7], [2, 5, 8],
  [0, 4, 8], [2, 4, 6]
]
export default {
  data () {
    return {
      player: 1,
      grids: [
        0, 0, 0,
        0, 0, 0,
        0, 0, 0,
      ],
    }
  },
  computed: {
    winner () {
      for (const [a, b, c] of winLineSets) {
        const sum = this.grids[a] + this.grids[b] + this.grids[c];
        if (sum === 3) return 1;
        if (sum === -3) return -1;
      }
      return 0;
    },
  },
  methods: {
    placeSymbol (index) {
      if (this.grids[index] !== 0) return;
      if (this.winner !== 0) return;
      this.grids[index] = this.player;
      this.player = -this.player; // change player, 1 -> -1, -1 -> 1
    },
    showSymbol (num) {
      return num === 0 ? '' : num === 1 ? 'O' : 'X';
    },
    reset () {
      this.grids = [0, 0, 0, 0, 0, 0, 0, 0, 0];
      this.player = 1;
    }
  },
}
</script>



<style>
#app {
  font-family: Avenir, Helvetica, Arial, sans-serif;
  -webkit-font-smoothing: antialiased;
  -moz-osx-font-smoothing: grayscale;
  text-align: center;
  display: flex;
  flex-direction: column;
  align-items: center;
  color: #2c3e50;
  margin: 20px 0;
  
}
h1 {
  font-size: 40px;
  width:400px;
  color:darkcyan;
  border-bottom: 1px dashed #046f6f;
}
.grids {
  display: flex;
  flex-wrap: wrap;
  width: 400px;
  height: 400px;
  align-content: flex-start;
  .grid {
    font-size: 60px;
    width: 33%;
    height: 33%;
    border: 1px solid gray;
    box-sizing: border-box;
    display: flex;
    justify-content: center;
    align-items: center;
    cursor: pointer;
  }
}
.info {
  font-size: 32px;
  margin-bottom:20px
  
}
.btn_reset {
  border: 0;
  background-color: #159fef;
  color: #fff;
  padding: 7px 15px;
  border-radius: 5px;
  font-size: 20px;
  margin: 0 0 20px 0;
  cursor: pointer;
}
.win {
  color: #c84d4d;
}
.player {
  margin-right: 30px;
}
</style>