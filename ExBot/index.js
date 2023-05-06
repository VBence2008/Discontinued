//npm init -y
//npm install discord.js dotenv firebase-admin fs
console.log("\nStarting ExBot...");
const packageJSON = require("./package.json");
require("dotenv").config();
const admin = require("firebase-admin");
const serviceAccount = require("./exbot-b79fb-firebase-adminsdk-bu1ng-df7d3e1394.json");
admin.initializeApp({
  credential: admin.credential.cert(serviceAccount),
  databaseURL:
    "https://exbot-b79fb-default-rtdb.europe-west1.firebasedatabase.app",
});
const db = admin.database();
const ref = db.ref();
const { Client, Intents, MessageEmbed } = require("discord.js");
const client = new Client({
  intents: [Intents.FLAGS.GUILDS, Intents.FLAGS.GUILD_MESSAGES],
});
let allcount = 0;
let sentcount = 0;
client.once("ready", () => {
  console.log(
    `\n------------------------------\nExBot is online on ${client.guilds.cache.size} servers:\n------------------------------\n`
  );
  let members = 0;
  client.guilds.cache.forEach((guild) => {
    console.log(`${guild.name} | ${guild.id}`);
    members += guild.memberCount;
  });
  ref.on("value", function (snapshot) {
    // var today = new Date();
    // var date =
    //   today.getFullYear() +
    //   "." +
    //   (today.getMonth() + 1) +
    //   "." +
    //   today.getDate();
    // var time =
    //   today.getHours() + "." + today.getMinutes() + "." + today.getSeconds();
    // var dateTime = date + "-" + time;
    // if (!fs.existsSync("./db")) {
    //   fs.mkdirSync("./db");
    // }
    // var json = JSON.stringify(snapshot.val(), null, 2);
    // fs.writeFile(`./db/${dateTime}.json`, json, (err) => {
    //   if (err) throw err;
    // });
    client.user.setStatus(snapshot.val().global.user.status.circle);
    client.user.setActivity(snapshot.val().global.user.status.text, {
      type: snapshot.val().global.user.status.type,
    });
    if (snapshot.val().global.user.status.text == "you") {
      client.user.setActivity(
        `${client.guilds.cache.size} guilds, ${members} users`,
        { type: "WATCHING" }
      );
    }
  });
});
client.on("messageCreate", (message) => {
  let members = 0;
  client.guilds.cache.forEach((guild) => {
    members += guild.memberCount;
  });
  ref.on("value", function (snapshot) {
    client.user.setStatus(snapshot.val().global.user.status.circle);
    client.user.setActivity(snapshot.val().global.user.status.text, {
      type: snapshot.val().global.user.status.type,
    });
    if (snapshot.val().global.user.status.text == "you") {
      client.user.setActivity(
        `${client.guilds.cache.size} guilds, ${members} users`,
        { type: "WATCHING" }
      );
    }
    let prefixtext = snapshot.val().global.prefix;
    let prefixlength = prefixtext.length;
    allcount++;
    let totalSeconds = client.uptime / 1000;
    let days = Math.floor(totalSeconds / 86400);
    totalSeconds %= 86400;
    let hours = Math.floor(totalSeconds / 3600);
    totalSeconds %= 3600;
    let minutes = Math.floor(totalSeconds / 60);
    let seconds = Math.floor(totalSeconds % 60);
    let uptime = `**${days}** days, **${hours}** hours, **${minutes}** minutes, **${seconds}** seconds`;
    if (message.author == client.user) {
      sentcount++;
    }
    if (message.content == "<@908810832903811144>") {
      const RespondEmbed = new MessageEmbed()
        .setColor("#66a0ff")
        .setTimestamp()
        .setTitle(
          "Hi! My prefix is `" +
            `${snapshot.val().global.prefix}` +
            "`, try `" +
            `${snapshot.val().global.prefix}` +
            "help` to see all my features!"
        )
        .setFooter({
          text:
            "Requested by: " + message.author.tag + " | ExBot by Bence#5579",
        });
      message.reply({ embeds: [RespondEmbed] });
    }
    if (message.content.startsWith(prefixtext)) {
      if (message.content.substring(prefixlength) == "help") {
        const HelpEmbed = new MessageEmbed()
          .setColor("#66a0ff")
          .setTimestamp()
          .setTitle("ExBot commands")
          .addFields(
            {
              name: snapshot.val().global.prefix + "help",
              value: "ExBot commands",
            },
            {
              name: snapshot.val().global.prefix + "owner",
              value: "Commands that are only for the bot owner",
            },
            {
              name: snapshot.val().global.prefix + "ping",
              value: "ExBot's responding",
            },
            {
              name: snapshot.val().global.prefix + "info",
              value: "ExBot contains more",
            },
            {
              name: snapshot.val().global.prefix + "exl",
              value: "Upload an ExLang file to run inside Discord",
            },
            {
              name: snapshot.val().global.prefix + "invite",
              value: "Bot invite link",
            }
          )
          .setFooter({
            text:
              "Requested by: " + message.author.tag + " | ExBot by Bence#5579",
          });
        message.reply({ embeds: [HelpEmbed] });
      }
      if (message.content.substring(prefixlength) == "owner") {
        const OwnerEmbed = new MessageEmbed()
          .setColor("#66a0ff")
          .setTimestamp()
          .setTitle("Commands that are only for the bot owner")
          .addFields(
            {
              name: snapshot.val().global.prefix + "leave",
              value: "Leave the current server",
            },
            {
              name:
                snapshot.val().global.prefix +
                "db <command> <value> ; <setting>",
              value:
                "Configure database. Commands: `set` `get` `add` `del` `rem`",
            },
            {
              name: snapshot.val().global.prefix + "stop",
              value: "Stop the bot",
            }
          )
          .setFooter({
            text:
              "Requested by: " + message.author.tag + " | ExBot by Bence#5579",
          });
        message.reply({ embeds: [OwnerEmbed] });
      }
      if (message.content.substring(prefixlength) == "ping") {
        const PingEmbed = new MessageEmbed()
          .setColor("#66a0ff")
          .setTimestamp()
          .setTitle("Pong!")
          .addField(
            "Latency",
            `${Date.now() - message.createdTimestamp}ms`,
            true
          )
          .addField("API latency", `${Math.round(client.ws.ping)}ms`, true)
          .setFooter({
            text:
              "Requested by: " + message.author.tag + " | ExBot by Bence#5579",
          });
        message.reply({ embeds: [PingEmbed] });
      }
      if (message.content.substring(prefixlength) == "info") {
        const InfoEmbed = new MessageEmbed()
          .setColor("#66a0ff")
          .setTimestamp()
          .setTitle("Information")
          .setThumbnail(
            "https://media.discordapp.net/attachments/908766278171377756/953302776732057680/botlogo3.png"
          )
          .addFields(
            {
              name: "Bot info",
              value: "Written in JavaScript\nLast updated on 2022.05.02",
            },
            {
              name: "Official Discord server",
              value: "https://discord.gg/y628cyE3d9",
            },
            {
              name: "YouTube channel (videos rarely)",
              value: "https://www.youtube.com/channel/UCIPy6JqEj4FqSXfG9Q4e_3A",
            },
            {
              name: "Meet the creator",
              value:
                "Main account: **Bence#5579**\nAlt account 1: **Bence Bro.#2681**\nAlt account 2: **Bence Jr. [Aiden]#3682**\nAlt account 3: **Bence Jr. [Anna]#4027**",
            },
            {
              name: "Servers",
              value: `ExBot is currently in **${client.guilds.cache.size}** guilds, with **${members}** users`,
            },
            {
              name: "Uptime",
              value: `${uptime}`,
            },
            {
              name: "Scanned messages (sent messages by everyone + this)",
              value: `${allcount + 1}`,
            },
            {
              name: "Responses (sent messages by ExBot + this)",
              value: `${sentcount + 1}`,
            },
            {
              name: "Discord.js version",
              value: packageJSON.dependencies["discord.js"].substring(1),
            }
          )
          .setFooter({
            text:
              "Requested by: " + message.author.tag + " | ExBot by Bence#5579",
          });
        message.reply({ embeds: [InfoEmbed] });
      }
      if (message.content.substring(prefixlength, prefixlength + 3) == "exl") {
        let exl = message.content.substring(prefixlength + 3);
        message.reply(exl);
      }
      if (message.content.substring(prefixlength) == "invite") {
        const PingEmbed = new MessageEmbed()
          .setColor("#66a0ff")
          .setTimestamp()
          .setTitle("Invite ExBot")
          .setURL(
            "https://discord.com/api/oauth2/authorize?client_id=908810832903811144&permissions=1644971949559&scope=bot"
          )
          .addField(
            "URL",
            "https://discord.com/api/oauth2/authorize?client_id=908810832903811144&permissions=1644971949559&scope=bot",
            true
          )
          .setFooter({
            text:
              "Requested by: " + message.author.tag + " | ExBot by Bence#5579",
          });
        message.reply({ embeds: [PingEmbed] });
      }
      if (
        message.content.substring(prefixlength) == "leave" &&
        (message.author.id == "713259922757779527" ||
          message.author.id == "848609387291344906" ||
          message.author.id == "957724189207457893" ||
          message.author.id == "957718010762764311")
      ) {
        const LeaveEmbed = new MessageEmbed()
          .setColor("#66a0ff")
          .setTimestamp()
          .setTitle("Leaving the server... Goodbye!")
          .setFooter({
            text:
              "Requested by: " + message.author.tag + " | ExBot by Bence#5579",
          });
        message.reply({ embeds: [LeaveEmbed] });
        message.guild.leave();
      }
      if (
        message.content.substring(prefixlength) == "stop" &&
        (message.author.id == "713259922757779527" ||
          message.author.id == "848609387291344906" ||
          message.author.id == "957724189207457893" ||
          message.author.id == "957718010762764311")
      ) {
        const ReloadEmbed = new MessageEmbed()
          .setColor("#66a0ff")
          .setTimestamp()
          .setTitle("Stopping bot...")
          .setDescription("Session data")
          .addFields(
            {
              name: "Uptime",
              value: `${uptime}`,
            },
            {
              name: "Scanned messages (sent messages by everyone + this)",
              value: `${allcount + 1}`,
            },
            {
              name: "Responses (sent messages by ExBot + this)",
              value: `${sentcount + 1}`,
            }
          )
          .setFooter({
            text:
              "Requested by: " + message.author.tag + " | ExBot by Bence#5579",
          });
        message.reply({ embeds: [ReloadEmbed] });
        setTimeout(() => {
          client.destroy();
          process.exit(0);
        });
      }
      if (
        message.content.substring(prefixlength, prefixlength + 2) == "db" &&
        (message.author.id == "713259922757779527" ||
          message.author.id == "848609387291344906" ||
          message.author.id == "957724189207457893" ||
          message.author.id == "957718010762764311")
      ) {
        if (
          message.content.substring(prefixlength + 3, prefixlength + 6) == "set"
        ) {
          // var today = new Date();
          // var date =
          //   today.getFullYear() +
          //   "." +
          //   (today.getMonth() + 1) +
          //   "." +
          //   today.getDate();
          // var time =
          //   today.getHours() +
          //   "." +
          //   today.getMinutes() +
          //   "." +
          //   today.getSeconds();
          // var dateTime = date + "-" + time;
          // if (!fs.existsSync("./db")) {
          //   fs.mkdirSync("./db");
          // }
          // var json = JSON.stringify(snapshot.val(), null, 2);
          // fs.writeFile(`./db/${dateTime}.json`, json, (err) => {
          //   if (err) throw err;
          // });
          let set = message.content.substring(prefixlength + 7);
          let setname = set.split(" ; ")[0];
          let setvalue = set.split(" ; ")[1];
          let setref = db.ref(`${setname}`);
          setref.once("value", (snapshot) => {
            if (snapshot.exists()) {
              if (snapshot.hasChildren()) {
                const SetEmbed = new MessageEmbed()
                  .setColor("RED")
                  .setTimestamp()
                  .setTitle("`" + setname + "` has children!")
                  .setDescription(
                    "Please delete every children of this node before setting a new value!"
                  )
                  .setFooter({
                    text:
                      "Requested by: " +
                      message.author.tag +
                      " | ExBot by Bence#5579",
                  });
                message.reply({ embeds: [SetEmbed] });
              } else {
                const SetEmbed = new MessageEmbed()
                  .setColor("GREEN")
                  .setTimestamp()
                  .setTitle("`" + setname + "` set to `" + setvalue + "`")
                  .setFooter({
                    text:
                      "Requested by: " +
                      message.author.tag +
                      " | ExBot by Bence#5579",
                  });
                message.reply({ embeds: [SetEmbed] });
                setref.set(setvalue);
                message = "";
              }
            } else {
              const SetEmbed = new MessageEmbed()
                .setColor("RED")
                .setTimestamp()
                .setTitle("`" + setname + "` doesn't exist!")
                .setDescription(
                  "Please use `add` to create this node before setting a new value!"
                )
                .setFooter({
                  text:
                    "Requested by: " +
                    message.author.tag +
                    " | ExBot by Bence#5579",
                });
              message.reply({ embeds: [SetEmbed] });
            }
          });
        }
        if (
          message.content.substring(prefixlength + 3, prefixlength + 6) == "get"
        ) {
          let get = message.content.substring(prefixlength + 7);
          let getref = db.ref(`${get}`);
          getref.once("value", (snapshot) => {
            if (snapshot.exists()) {
              const GetEmbed = new MessageEmbed()
                .setColor("GREEN")
                .setTimestamp()
                .setTitle("Value of `" + get + "`")
                .setDescription(
                  "```json\n" + JSON.stringify(snapshot.val(), null, 2) + "```"
                )
                .setFooter({
                  text:
                    "Requested by: " +
                    message.author.tag +
                    " | ExBot by Bence#5579",
                });
              message.reply({ embeds: [GetEmbed] });
            } else {
              const GetEmbed = new MessageEmbed()
                .setColor("RED")
                .setTimestamp()
                .setTitle("`" + get + "` doesn't exist!")
                .setDescription(
                  "Please use `add` to create this node before getting the value!"
                )
                .setFooter({
                  text:
                    "Requested by: " +
                    message.author.tag +
                    " | ExBot by Bence#5579",
                });
              message.reply({ embeds: [GetEmbed] });
            }
          });
        }
        if (
          message.content.substring(prefixlength + 3, prefixlength + 6) == "add"
        ) {
          let add = message.content.substring(prefixlength + 7);
          let addref = db.ref(`${add}`);
          addref.once("value", (snapshot) => {
            if (snapshot.exists()) {
              const AddEmbed = new MessageEmbed()
                .setColor("RED")
                .setTimestamp()
                .setTitle("`" + add + "` already exists!")
                .setDescription(
                  "Please use `set` to set a new value to this node!"
                )
                .setFooter({
                  text:
                    "Requested by: " +
                    message.author.tag +
                    " | ExBot by Bence#5577",
                });
              message.reply({ embeds: [AddEmbed] });
            } else {
              const AddEmbed = new MessageEmbed()
                .setColor("GREEN")
                .setTimestamp()
                .setTitle("`" + add + "` added!")
                .setFooter({
                  text:
                    "Requested by: " +
                    message.author.tag +
                    " | ExBot by Bence#5579",
                });
              message.reply({ embeds: [AddEmbed] });
              addref.set("");
            }
          });
        }
        if (
          message.content.substring(prefixlength + 3, prefixlength + 6) == "del"
        ) {
          let del = message.content.substring(prefixlength + 7);
          let delref = db.ref(`${del}`);
          delref.once("value", (snapshot) => {
            if (snapshot.exists()) {
              if (snapshot.hasChildren()) {
                const DelEmbed = new MessageEmbed()
                  .setColor("RED")
                  .setTimestamp()
                  .setTitle("`" + del + "` has children!")
                  .setDescription(
                    "Please delete every children of this node before deleting this node!"
                  )
                  .setFooter({
                    text:
                      "Requested by: " +
                      message.author.tag +
                      " | ExBot by Bence#5579",
                  });
                message.reply({ embeds: [DelEmbed] });
              } else {
                const DelEmbed = new MessageEmbed()
                  .setColor("GREEN")
                  .setTimestamp()
                  .setTitle("`" + del + "` deleted!")
                  .setFooter({
                    text:
                      "Requested by: " +
                      message.author.tag +
                      " | ExBot by Bence#5579",
                  });
                message.reply({ embeds: [DelEmbed] });
                delref.set("");
              }
            } else {
              const DelEmbed = new MessageEmbed()
                .setColor("RED")
                .setTimestamp()
                .setTitle("`" + del + "` doesn't exist!")
                .setDescription(
                  "Please use `add` to create this node before deleting it!"
                )
                .setFooter({
                  text:
                    "Requested by: " +
                    message.author.tag +
                    " | ExBot by Bence#5579",
                });
              message.reply({ embeds: [DelEmbed] });
            }
          });
        }
      }
    }
  });
  message = "";
});
client.login(process.env.TOKEN);
