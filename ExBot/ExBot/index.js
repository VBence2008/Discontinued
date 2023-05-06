//npm init -y
//npm install discord.js dotenv mongoose fs
console.log("\n🔃 Starting ExBot...");
const package = require("./package.json");
console.log("✅ File 'package.json' is ready");
require("dotenv").config();
console.log("✅ Package 'dotenv' is ready");
const mongoose = require("mongoose");
console.log("✅ Package 'mongoose' is ready");
const Discord = require("discord.js");
const client = new Discord.Client({
  intents: [Discord.Intents.FLAGS.GUILDS, Discord.Intents.FLAGS.GUILD_MESSAGES],
});
console.log("✅ Package 'discord.js' is ready");
const fs = require("fs");
console.log("✅ Package 'fs' is ready");
let allcount = 0;
let sentcount = 0;
client.on("ready", async () => {
  await mongoose
    .connect(process.env.MONGO_URI || "", {
      keepAlive: true,
    })
    .then(() => {
      console.log("✅ Connecion to MongoDB database is ready");
    })
    .catch((err) => {
      console.log("❌ Connecion to MongoDB database is not ready: " + err);
    });
  console.log(
    `\n------------------------------\nExBot is online on ${client.guilds.cache.size} servers:\n------------------------------\n`
  );
  let memberCount = 0;
  client.guilds.cache.forEach((guild) => {
    console.log(`${guild.name} | ${guild.id}`);
    memberCount += guild.memberCount;
  });
  mongoose.pluralize(null);
  const schema = new mongoose.Schema({
    _id: Number,
    __v: Boolean,
    ID: Number,
    TITLE: String,
    DESCRIPTION: String,
    FLAG: String,
    DATE: Date,
    VALUE: Object,
  });
  const model = mongoose.model("exbot", schema);
});
client.login(process.env.TOKEN);
