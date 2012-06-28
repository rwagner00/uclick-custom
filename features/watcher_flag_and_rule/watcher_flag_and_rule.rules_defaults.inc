<?php
/**
 * @file
 * watcher_flag_and_rule.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function watcher_flag_and_rule_default_rules_configuration() {
  $items = array();
  $items['rules_email_watcher'] = entity_import('rules_config', '{ "rules_email_watcher" : {
      "LABEL" : "Email Watcher",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "email", "property", "watcher" ],
      "REQUIRES" : [ "flag", "rules" ],
      "ON" : [ "node_update" ],
      "DO" : [
        { "flag_fetch_users_node" : {
            "USING" : { "flag" : "property_watch", "node" : [ "node" ] },
            "PROVIDE" : { "users" : { "users" : "Users who flagged" } }
          }
        },
        { "LOOP" : {
            "USING" : { "list" : [ "users" ] },
            "ITEM" : { "list_item" : "Current list item" },
            "DO" : [
              { "mail" : {
                  "to" : [ "list-item:mail" ],
                  "subject" : "Test",
                  "message" : "Test Message",
                  "language" : [ "" ]
                }
              }
            ]
          }
        }
      ]
    }
  }');
  return $items;
}
