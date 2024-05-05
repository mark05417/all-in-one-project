<template>
  <div id="app">
    <TodoList />
    <TicTacToe />
  </div>
</template>

<script>
import TodoList from './components/TodoList.vue';
import TicTacToe from './components/TicTacToe.vue';

export default {
  name: 'App',
  components: {
    TodoList,
    TicTacToe,
  }
};
</script>

<style>
/* 可以添加一些全局的 CSS 樣式 */
</style>
