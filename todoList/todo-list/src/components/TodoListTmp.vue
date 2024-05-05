<template>
  <div>
    <h1>Todo List</h1>
    <input type="text" v-model="newTodo" @keyup.enter="addTodo">
    <ul>
      <li v-for="(todo, index) in todos" :key="index">{{ todo }}</li>
    </ul>
  </div>
</template>

<script>
export default {
  data() {
    return {
      newTodo: '',
      todos: []
    };
  },
  methods: {
    addTodo() {
      if (this.newTodo.trim() !== '') {
        this.todos.push(this.newTodo);
        this.newTodo = '';
      }
    }
  }
};
</script>

<style scoped>
/* 可以添加一些 CSS 樣式來美化你的 TodoList */
</style>
